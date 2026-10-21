#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define INIT_CAPACITY 16      // 初始桶数量
#define LOAD_FACTOR   0.75    // 装填因子上限

/* ---------- 链表节点 ---------- */
typedef struct Entry {
    char         *key;     // key 由表自己复制一份，调用者不必保留
    int           value;
    struct Entry *next;    // 同桶冲突链
} Entry;

/* ---------- 散列表本体 ---------- */
typedef struct {
    Entry **buckets;        // 桶数组，每个元素是链表头
    size_t  capacity;       // 桶数量（保持 2 的幂）
    size_t  size;           // 已存元素个数
} HashMap;

/* ---------- 工具函数 ---------- */
static char *dup_str(const char *s) {
    size_t n = strlen(s) + 1;
    char *p = (char *)malloc(n);
    if (p) memcpy(p, s, n);
    return p;
}

/* FNV-1a 哈希：速度快，分布均匀 */
static uint64_t fnv1a(const char *s) {
    uint64_t h = 1469598103934665603ULL;   // offset basis
    while (*s) {
        h ^= (unsigned char)*s++;
        h *= 1099511628211ULL;             // FNV prime
    }
    return h;
}

static size_t bucket_of(const char *key, size_t cap) {
    return (size_t)(fnv1a(key) % cap);
}

/* ---------- 创建 / 销毁 ---------- */
HashMap *hm_create(void) {
    HashMap *m = (HashMap *)malloc(sizeof *m);
    if (!m) return NULL;
    m->capacity = INIT_CAPACITY;
    m->size     = 0;
    m->buckets  = (Entry **)calloc(m->capacity, sizeof(Entry *));
    if (!m->buckets) { free(m); return NULL; }
    return m;
}

void hm_free(HashMap *m) {
    if (!m) return;
    for (size_t i = 0; i < m->capacity; i++) {
        Entry *e = m->buckets[i];
        while (e) {
            Entry *next = e->next;
            free(e->key);
            free(e);
            e = next;
        }
    }
    free(m->buckets);
    free(m);
}

/* ---------- 扩容 ---------- */
static int hm_resize(HashMap *m, size_t newcap) {
    Entry **nb = (Entry **)calloc(newcap, sizeof(Entry *));
    if (!nb) return -1;

    for (size_t i = 0; i < m->capacity; i++) {
        Entry *e = m->buckets[i];
        while (e) {
            Entry *next = e->next;            // 先记住下一个
            size_t idx  = bucket_of(e->key, newcap);
            e->next     = nb[idx];            // 头插法挂到新桶
            nb[idx]     = e;
            e           = next;
        }
    }
    free(m->buckets);
    m->buckets  = nb;
    m->capacity = newcap;
    return 0;
}

/* ---------- 插入 / 更新 ---------- */
int hm_put(HashMap *m, const char *key, int value) {
    size_t idx = bucket_of(key, m->capacity);

    // 已存在则只更新 value
    for (Entry *e = m->buckets[idx]; e; e = e->next) {
        if (strcmp(e->key, key) == 0) {
            e->value = value;
            return 0;
        }
    }

    // 插入前检查是否需要扩容
    if ((double)(m->size + 1) / m->capacity > LOAD_FACTOR) {
        if (hm_resize(m, m->capacity * 2) != 0) return -1;
        idx = bucket_of(key, m->capacity);    // 容量变了，重算
    }

    Entry *e = (Entry *)malloc(sizeof *e);
    if (!e) return -1;
    e->key = dup_str(key);
    if (!e->key) { free(e); return -1; }
    e->value = value;
    e->next  = m->buckets[idx];   // 头插法
    m->buckets[idx] = e;
    m->size++;
    return 0;
}

/* ---------- 查找 ---------- */
int hm_get(const HashMap *m, const char *key, int *out) {
    size_t idx = bucket_of(key, m->capacity);
    for (const Entry *e = m->buckets[idx]; e; e = e->next) {
        if (strcmp(e->key, key) == 0) {
            if (out) *out = e->value;
            return 1;
        }
    }
    return 0;   // 未找到
}

/* ---------- 删除 ---------- */
int hm_remove(HashMap *m, const char *key) {
    size_t idx = bucket_of(key, m->capacity);
    Entry **pp = &m->buckets[idx];        // 二级指针：省去前驱记录
    while (*pp) {
        Entry *e = *pp;
        if (strcmp(e->key, key) == 0) {
            *pp = e->next;
            free(e->key);
            free(e);
            m->size--;
            return 1;
        }
        pp = &e->next;
    }
    return 0;
}

/* ---------- 调试打印 ---------- */
void hm_dump(const HashMap *m) {
    printf("size=%zu capacity=%zu\n", m->size, m->capacity);
    for (size_t i = 0; i < m->capacity; i++) {
        if (!m->buckets[i]) continue;
        printf("  [%2zu]", i);
        for (Entry *e = m->buckets[i]; e; e = e->next)
            printf(" -> (%s:%d)", e->key, e->value);
        printf("\n");
    }
}

/* ---------- 演示 ---------- */
int main(void) {
    HashMap *m = hm_create();
    if (!m) return 1;

    const char *keys[] = {"apple", "banana", "cherry", "date",
                          "elder", "fig", "grape", "honey"};
    for (int i = 0; i < 8; i++)
        hm_put(m, keys[i], i * 10);

    hm_put(m, "apple", 999);          // 覆盖测试
    hm_dump(m);

    int v;
    if (hm_get(m, "cherry", &v)) printf("cherry = %d\n", v);
    if (!hm_get(m, "kiwi", &v))  printf("kiwi 不存在\n");

    hm_remove(m, "banana");
    printf("删除 banana 后 size=%zu\n", m->size);

    hm_free(m);
    return 0;
}