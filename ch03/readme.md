【链表】

链表是由许多相同数据类型的数据项，按特定顺序排列而成的线性表。
但链表的特性是其各个数据项在计算机内存中的位置是不连续且随机存放的。
优点是数据的插入或删除都相当方便，有新数据加入就向系统申请一块内存空间，而数据被删除后，
就可以把空间还给系统，加入和删除都不需要移动大量的数据。
其缺点是设计数据结构时较为麻烦，另外在查找数据时，也无法像静态数据（如数组）那样可随机读取数据，
必须按序查找到该数据为止。

日常生活中有许多链表的抽象应用，例如可以把“单向链表”想象成火车，有多少人就接多少节的车厢，当
假日人多时，需要较多车厢时就可多接些车厢，人少时就把车厢数量减少，十分具有弹性。
像游乐场中的摩天轮就是一种“环形链表”的应用，可以根据需要增加车厢的数量。

【动态分配内存】

如果变量或对象在使用动态方式分配内存后，事后必须进行释放的操作，否则这些动态分配的内存会一直存在，
因而造成“内存漏失”(memory leak)的现象。

【C++的动态分配变量】

在C++中，如果要动态分配内存则必须使用new关键词来获取内存地址。如果是单一变量，声明方式如下所示：

     数据类型* 指针名称 = new 数据类型;
或 

     数据类型* 指针名称 = new 数据类型(初值);//指定初始值的声明方式

也可以分为两段式声明：
     
     数据类型* 指针名称 = 0;
     指针名称 = new 数据类型;
或

     数据类型* 指针名称 = 0;
     指针名称 = new 数据类型(初始值);

例如：
    
    int* n = new int;

上列声明中，new关键词的功能是动态地分配一块可以存放int类型数据的内存空间，如果分配操作成功，就会返回
这块内存空间的起始地址，这时指针n就会指向这块内存的起始地址；如果分配操作失败，就会返回NULL（也即是0）,
指针n的内容就是NULL。
在C++中，如果使用动态分配内存方式，用完之后，最好使用delete关键词来释放这些已分配的内存空间，方式如下所示：
    
     delete 指针名称;

【动态分配数组】

当数据声明为数组时，在编译阶段即确定了数组的长度，但是这样很容易造成内存的浪费或无法满足程序所需的问题。
以上问题可以通过动态分配数组的方式来轻松解决。
也就是说，利用动态分配数组，就可以在程序执行时，再临时决定数组的大小。动态分配数组方式与动态分配变量十分类似，
声明后会在内存中自动寻找适合的连续存储空间，其长度必须和指定数据类型再乘以数组长度的乘积相符。
分配完成后，再将该内存区段的起始地址，返回给等号左边所声明的指针变量。

下面就是动态分配一维数组的方式，语法如下：

   数据类型 *指针数组变量 = new 数据类型[元素个数];
分配动态数组时，须在中括号内指定预分配数组的元素个数。当分配成功时，系统会返回该数组的起始地址，否则返回NULL值。
当分配的动态数组在程序中已不再使用时，也必须使用delete运算符来释放该动态数组。

delete 运算符释放动态数组的使用格式如下所示：

    delete [] 指针数组变量;

【单向链表】

在动态分配内存空间时，最常使用的就是“单向链表”(single linked list)。
一个单向链表节点基本上由两个元素，即数据字段和指针组成，而指针将会指向下一个元素的内存所在的位置。
在“单向链表”中第一个节点是“链表头指针”，指向最后一个节点的指针设为NULL，表示它是“链表尾”，不指向任何地方。
由于单向链表中所有节点都知道节点本身的下一个节点在哪里，但是对于前一个节点却没有办法知道所以在单向链表的各种操作中，
"链表头指针"就显得相当重要，只要存在链表头指针，就可以遍历整个链表，进行加入和删除节点等操作。注意，除非必要，否则不可移动链表头指针。

【单向链表的创建与遍历】

在C++中，若以动态分配产生链表节点的方式，可以先行定义一个类数据类型，接着在类中定义一个指针变量，其数据类型与此类相同，
作用是指向下一个链表节点，另外类中至少要有一个数据字段。
例如，声明一个学生成绩链表节点的结构，并且包含下面两个数据字段：姓名（name），成绩(score),与一个指针(next)。
接着就可以动态创建链表中的每个节点。

假设现在要新增一个节点至链表的末尾，且ptr指向链表的第一个节点，在程序上必须设计以下4个步骤。
Step1:动态分配内存空间给新节点使用。
Step2:将原链表尾部的指针(next)指向新元素所在的内存位置（即内存地址）。
Step3:将ptr指针指向新节点的内存位置，表示这是新的链表尾部。
Step4:由于新节点当前为链表的最后一个元素，所以将它的指针(next)指向NULL。

例如要将s1的next变量指向s2的内存地址，而s2的next变量指向NULL。
s1.next = &s2;
s2.next = NULL;

由于链表的基本特性就是next变量将会指向下一个节点的内存地址，这时s1节点与s2节点间的关系就是单向链节点建立连接的情况。
遍历(traverse)单向链表中的过程，就是使用指针运算来访问链表中的每个节点。
如果要遍历已建立了3个节点的单向链表，可使用结构指针ptr来作为链表的读取游标，一开始是指向链表的头。
每次读取链表的一个节点，就将ptr往下一个节点移动(即指向下一个节点)，直到ptr指向NULL为止。

有的时候，链表中的节点不只记录单个数值，例如每一个节点除了有指向下一个节点的指针变量外，还包括了记录一位学生的姓名(name),座位(no),
成绩(score)。因此，首先必须声明节点的数据类型，让每一个节点包含一个指针变量，以指向下一个节点，使所有数据能被链接在一起形成一个
链表结构。
节点数据类型的声明如下：
class list   //链表结构的声明
{            //类内容以(...);包起来
    public:
    int num;//座号
    char name[10];//姓名
    int score;//成绩
    class list *next;//指针变量，指向下一个节点
};

【单向链表插入新节点】

在单向链表中插入新节点，如同一列火车中加入新的车厢，有3种情况：

1)加到第1个节点之前
2)加到最后一个节点之后
3)加到链表中间任一位置

针对第1种情况，新节点插入第一个节点之前，即成为此链表的首节点:只需把新节点的指针指向
链表原来的第一个节点，再把链表头指针指向新节点即可。

    newnnode->next = first;
    first = newnode;

针对第2种情况，新节点插入最后一个节点之后，只需把链表的最后一个节点的指针指向新节点，
新节点的指针再指向NULL即可。

     ptr->next = newnode;
     newnode->next = NULL;

 针对第3种情况，将新节点插入链表中间的位置:例如插入的节点是在X与Y之间，只要将X节点的指针指向
 新节点，新节点的指针指向Y节点即可。

     newnode->next = x->next;//x的伙伴成了新节点的伙伴，x没伙伴了
     x->next = newnode;//新节点成为了x的伙伴

【单向链表删除节点】

在单向链表类型的数据结构中，若要在链表中删除一个节点，如同一列火车中拿掉原有的车厢，根据所删除节点的位置
会有3种不同的情况。

1)删除链表的第一个节点:只要把链表头指针指向第二个节点即可。

   top=head;
   head=head->next;
   free(top);

2)删除链表的最后一个节点:只要指向最后一个节点的指针，直接指向NULL即可。

   ptr->next = tail;
   ptr->next = NULL;
   free(tail);

3)删除链表内的中间节点：只要将删除节点的前一个节点的指针，指向将要被删除节点的下一个节点即可。

   Y = ptr->next;//Y是ptr的小伙伴
   ptr->next = Y->next;//将Y的小伙伴作为ptr的小伙伴
   free(Y);//丢弃Y了

 【单向链表的反转】
  
  了解了单向链表节点的删除和插入之后，大家可以发现在这种具有方向性的链表结构中增删节点是相当容易的一件事。
  而从头到尾输出整个单向链表也不难，但是如果要反转过来输出单向链表就需要某些技巧了。
  在单向链表中的节点特性是知道下一个节点的位置，可是却无从得知它的上一个节点的位置。
  如果要将单向链表反转，则必须使用3个指针变量。

    struct list //链表结构的声明
    {
         int num;//学生号码
         int score;//学生分数
         char name[10];//学生姓名
         struct list *next;//指向下一个节点
    };
    typedef struct list node;//定义node新的数据类型
    typedef node *link;//定义link新的数据类型指针
    link invert(link x) //x为链表的开始指针
    {
         link p,q,r;
         p=x;//将p指向链表的开头
         q=NULL;//q是p的前一个节点
         while(p!=NULL)
         {
              r=q;//将r接到q之后
              q=p;//将q接到p之后
              p=p->next;//p移到下一个节点
              q->next=r;//q接到之前的节点
         }
         return q;
    }

 【环形链表】
  1）环形链表中插入新节点
  2) 环形链表节点的删除
  3) 环形链表的连接功能

 【双向链表】
  1)双向链表的建立与遍历
  2)双向链表中加入新节点
  3)双向链表节点的删除
  
  【链表相关应用简介】
   1)多项式表示法
   2）稀疏矩阵表示法
   