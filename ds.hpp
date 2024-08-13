// powerd by https://github.com/Ansurfen/DS408

typedef int *ElemType;
#define MAXSIZE 1000

// 线性表的动态分配顺序存储结构

typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

// 线性表的单链表存储结构

typedef struct
{
    ElemType data;
    LNode *next;
} LNode, *LinkList;

// 线性表的静态单链表存储结构

typedef struct
{
    ElemType data;
    int cur;
} component, SLinkList[MAXSIZE];

// 线性表的双向链表存储结构

typedef struct
{
    ElemType data;
    DuLNode *prior, *next;
} DuLNode, *DuLinkList;

// 带头节点的线性链表存储结构

typedef struct Link
{
    ElemType data;
    struct Link *next;
} *Link, *Position;

typedef struct
{
    struct Link head, tail;
    int len;
} HLinkList;

// 顺序栈

typedef ElemType SElemType;

typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

// 单链队列

typedef ElemType QElemType;

typedef struct
{
    QElemType data;
    QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;
} LinkQueue;

// 循环队列

typedef struct
{
    QElemType *base;
    int front, rear;
} SqQueue;

// 静态串

typedef unsigned char SString[MAXSIZE + 1]; // 0号单元存储串的长度

// 动态串

typedef struct
{
    char *ch;
    int length;
} HString;

// 串的块链存储

#define CHUNKSIZE 80

typedef struct
{
    char ch[CHUNKSIZE];
    Chunk *next;
} Chunk;

typedef struct
{
    Chunk *head, *tail;
    int curlen;
} LString;

// 数组的顺序表示

typedef struct
{
    ElemType *base;
    int dim;        // 维数
    int *bounds;    // 数组维界基址
    int *constants; // 数组映像函数常量基址
} Array;

// 稀疏矩阵

typedef struct
{
    int i, j; // 行和列下标
    ElemType e;
} Triple;

typedef struct
{
    Triple data[MAXSIZE + 1]; // data[0]不使用
    int mu, nu, tu;           // 矩阵行数，列数以及非零元的个数
} TSMatrix;

// 行逻辑链接的顺序表

#define MAXRC MAXSIZE

typedef struct
{
    Triple data[MAXSIZE + 1]; // 非零元三元组表
    int rpos[MAXRC + 1];      // 各行第一个非零元的位置表
    int mu, nu, tu;           // 矩阵行数，列数以及非零元的个数
} RLSMatrix;

// 稀疏矩阵的十字链表法

typedef struct
{
    int i, j;
    ElemType e;
    OLNode *right, *down; // 该非零元所在的行表和列表的后继链域
} OLNode, *OLink;

typedef struct
{
    OLink *rhead, *chead;
    int mu, nu, tu;
} CrossList;

// 广义表
// 略

// 二叉树

typedef ElemType TElemType;

typedef struct
{
    TElemType data;
    BiTNode *lc, rc;
} BiTNode, *BiTree;

// 线索二叉树

typedef enum PointerTag
{
    Link,
    Thread
};

typedef struct
{
    TElemType data;
    BiThrNode *lc, rc;
    PointerTag LTag, RTag;
} BiThrNode, *BiThrTree;

// 树的双亲表示法

typedef struct
{
    TElemType data;
    int parent;
} PTNode;

typedef struct
{
    PTNode nodes[MAXSIZE];
    int r, n; // 根的位置和节点数
} PTree;

// 树的孩子链表表示法

typedef struct
{
    int child;
    CTNode *next;
} CTNode, *ChildPtr; // 孩子节点

typedef struct
{
    TElemType data;
    ChildPtr firstchild; // 孩子链表表头指针
} CTBox;

typedef struct
{
    CTBox nodes[MAXSIZE];
    int r, n; // 根的位置和节点数
} CTree;

// 孩子兄弟表示法

typedef struct
{
    ElemType data;
    CSNode *firstchild, *nextsibling;
} CSNode, *CSTree;

// 并查集

typedef PTree MFSet;

// 哈夫曼树

typedef struct
{
    unsigned int weight;
    unsigned int parent, lc, rc;
} HTNode, *HuffmanTree;

typedef char **HuffmanCode; // 哈夫曼编码表

// 邻接矩阵

typedef enum
{
    DG,
    DN,
    UDG,
    UDN
} GrapKind; // {有向图，有向网，无向图，无向网}

typedef int VRType; // 顶点关系类型。对无权图，用1或者0表示是否相邻，对带权图为权值类型
typedef char VertexType;

typedef void *InfoType; // 弧的相关信息

typedef struct
{
    VRType adj;
    InfoType *info;
} ArcCell, AdjMatrix[MAXSIZE][MAXSIZE];

typedef struct
{
    VertexType vexs[MAXSIZE]; // 顶点向量
    int vexnum, arcnum;       // 顶点数和弧数
    AdjMatrix arcs;           // 邻接矩阵
    GrapKind kind;            // 图的种类标志
} MGraph;

// 邻接表

typedef struct
{
    int adjvex;       // 该弧所指向的顶点位置
    ArcNode *nextarc; // 指向下一条弧的指针
    InfoType *info;
} ArcNode;

typedef struct
{
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MAXSIZE];

typedef struct
{
    AdjList vertices;
    int vexnum, arcnum;
    int kind;
} ALGraph;

// 有向图的十字链表存储

typedef struct
{
    int tailvex, headvex; // 该弧的尾和头顶点的位置
    ArcBox *hlink, *tlink;
    InfoType *info;
} ArcBox;

typedef struct
{
    VertexType data;
    ArcBox *firstin, *firstout; // 该顶点的第一个入弧和出弧
} VexNode;

typedef struct
{
    int vexnum, arcnum;
    VexNode xlist[MAXSIZE];
} OLGraph;

// 无向图的邻接多重表

typedef enum
{
    unvisited,
    visited
} VisitIf;

typedef struct
{
    VisitIf mark;       // 访问标记
    int ivex, jvex;     // 该边依附的两个顶点
    EBox *ilink, jlink; // 依附这两个顶点的下一条边
    InfoType *info;
} EBox;

typedef struct
{
    VertexType data;
    EBox *firstedge;
} VexBox;

typedef struct
{
    VexBox adjmulist[MAXSIZE];
    int vexnum, arcnum;
} AMLGraph;

// AVL

typedef struct
{
    ElemType data;
    int bf; // 平衡因子
    BSTNode *lc, rc;
} BSTNode, *BSTree;

// B-树

#define m 3 // 阶数，假设3阶

typedef char KeyType;
typedef ElemType Record;

typedef struct
{
    int keynum; // 关键字个数
    BTNode *parent;
    KeyType key[m + 1];
    BTNode *ptr[m + 1];
    Record *recptr[m + 1];
} BTNode, *BTree;

typedef struct
{
    BTNode *pt;
    int i;
    int tag;
} Result;

// 开放定址哈希表

int hashsize[] = {}; // 哈希表容量递增表

typedef struct
{
    ElemType *elem; // 数据元素的存储基址
    int count;      // 当前数据元素的个数
    int sizeindex;  // hashsize[sizeindex]为当前容量
} HashTable;
