
2022-3-15 增加了CH02LinearList:2023年数据结构考研复习指导
--------------------------
2021-12-09 ch02 程序说明：
  【线性表】

   C/C++程序中的数组或字符串结构，就是一种典型线性表的应用，
   在计算机中是属于内存中的静态数据结构(static data structure),
   特性是使用连续的存储空间(contiguous allocation)来存储。
   在编译时就必须把内存分配给相关的变量，不过这容易造成内存的浪费。

   链表（linked lists）结构，在C/C++中，多半是以指针变量类型来实现线性表的数据结构，
   特点是链表节点的内存分配是在执行时才会发生，所以不需要事先声明，这样能够充分节省内存，
   这种内存分配被称为“动态内存分配”（dynamic memory allocation）。

   多项式也是线性表这类数据结构充分发挥作用的地方，如果使用计算机来处理多项式的各种相关运算，
   就可以将多项式以数组(array)或链表(linked list)形式来存储。

指针变量是指内含值为指到内存存储位置的一种数据类型变量

  【数组】

   在程序设计语言中，可看作是具有相同名称与相同数据类型的变量的集合，并且在内存中占有一块
   连续的内存空间。要存取数组中的数据时，则需要使用下标(index,或称"索引")来定位数据在数组中的
   位置。
   在不同的程序设计语言中，数组结构类型的声明也有差异，但通常必须包含下列5种属性：

   1.起始地址：表示数组名（或数组第一个元素）所在内存中的起始地址。
   2.维数(dimension):代表此数组为几维数组，如一维数组，二维数组，三维数组等等。
   3.下标的上下限：指元素在此数组中，内存所存储位置的最小值与最大值。
   4.数组元素的个数：是下标上限与下标下限的差+1。
   5.数组类型：声明此数组的类型，它决定数组元素在内存所占空间的大小。

   多维数组也必须在一维的物理内存中来表示，因为内存地址是按线性顺序递增的。
   通常情况下，按照不同的程序设计语言，又可区分为两种方式：

   1)以行为主（row-major）:一行一行来按序存储，例如Java,C/C++,PASCAL语言的数组存放方式。

   2)以列为主(column-major):一列一列来按序存储,例如Fortan。

数据类型：表示该数组存放的数据类型，可以是基本的数据类型(如int,float,char...等)，或扩展的
        数据类型，如结构类型(struct)等。
数组名： 命名规则与变量相同。
元素的个数：表示数组可存放的数据个数，为一个正整数的常数，且数组的下标值是从0开始。
          若是只有中括号，即没有指定常数值，则表示定义的是不定长度的数组(数组的长度会由设置初始值
          的个数决定)

二维数组：例如一个含有m*n个元素的二维数组A(1:m,1:n),m代表行数，n代表列数。

1.以行为主:假设a为数组A在内存中的起始地址，d为单位空间，那么数组元素aij与内存地址有下列关系：

    Loc(aij) = a + n*(i-1)*d + (j-1)*d (i,j从1开始)

2.以列为主：假设a为数组A在内存中的起始地址，d为单位空间，那么数组元素aij与内存地址有下列关系：

    Loc(aij) = a + (i-1)*d + m*(j-1)*d  (i,j从1开始)


如果把数组A声明成A(m1:m2,n1:n2),且对任意aij.有m2>=i>=m1,n2>=j>=n1,这种方式称为"标注表示法"。
此数组共有(m2-m1+1)行，(n2-n1+1)列。
假设a仍为起始地址，而且m=m2-m1+1,n=n2-n1+1
于是导出：


1)以行为主：

    Loc(aij) = a + ((i-m1+1)-1)*n*d + ((j-n1+1)-1)*d
            = a + (i-m1)*n*d + (j-n1)*d
2)以列为主：

    Loc(aij) = a + ((i-m1+1)-1)*d + ((j-n1+1)-1)*m*d
            = a + (i-m1)*d + (j-n1)*m*d

在C++语言中，二维数组的声明格式如下：

    数据类型 二维数组名[行大小][列大小]

以arr[3][5]来说明,arr为一个3行5列的二维数组，也可以视为3x5的矩阵。
在存取二维数组中的数据时，使用的下标值仍然是从0开始计算。
至于在二维数组设置初始值时，为了便于分隔行和列，所以除了最外层的{}外，最好用{}括住每一行的元素初始值，
并以","分隔每个数组元素，语法如下：

    数据类型 数组名[n][列大小]={{第0行初始值},{第1行初始值},...,{第n-1行初始值}}


  【结构数组】

结构与数组的作用同样是用来建立数据集合，它以C++现有的数据类型作为基础，允许用户建立自定义数据类型，又称为派生数据类型。
简单来说，就是将一组相关的却拥有不同数据类型的数组组合在一起称为一种新的数据类型。结构类型必须具有结构名称与结构项目，
而且必须使用关键词struct来创建，一个结构的基本声明方式如下所示：

    struct 结构名称
    {
      数据类型 结构成员1；
      数据类型 结构成员2；
    }

在结构定义中可以使用基本的变量，数组，指针，甚至是其他结构成员等。另外，注意在定义之后的分号不可省略。
在定义了结构之后，可以直接使用它来创建结构对象，结构定义本身就像是创建对象的蓝图或模子，而结构对象则是根据这个蓝图
制造出来的成品或模型，每个被创建的结构对象都拥有相同的结构成员。也可以在定义结构的同时声明结构变量。
在创建结构对象之后，可以使用英文句号来存取结构成员，这个句号通常被称为“点运算符”（dot operator）。只要
在结构变量后加上成员运算符"."与结构成员名称，就可以直接存取该项数据：

    结构变量.项目成员名称；

结构数组则是将结构数据类型与数组相结合的应用。简单来说，结构可以集合不同的数据类型，如果同时要记录多个相同的结构数组，
就需要声明一个结构数组类型。声明方式如下：

    struct 结构类型名称 结构数组名[元素个数];

下面这个代码段将创建具有5个元素的结构数组：

    struct student
    {
      char name[10];
      int math;
      int english;
    };
    struct student class1[5];

要存取数组的结构成员，在数组后方加上"[下标值]"再加上成员名称即可，例如：

    结构数组名[下标值].成员名称

  【C++的字符串】

在C/C++中，并没有字符串的基本数据类型，如果要存储字符串，基本上还是需要使用字符数组。
不过，在C++标准类数据库中还定义了新的字符串类string,让大家可以更轻松地处理字符串。

字符串声明的最重要特点是必须使用空字符('\0')来代表每一个字符串的结束，例如'a'与"a"分别
代表字符常数和字符串常数，其中'a'的长度为1，"a"的长度为2。字符串声明方式如下所示：

    方式1:char字符串变量[字符串长度]="初始字符串";
    方式2:char 字符串变量[字符串长度]={'字符1'，'字符2',...,'字符n','\0'};

“方式1”的声明方式会自动在字符串结尾附加'\0'结尾字符，至于“方式2”则是以字符数组
来进行初始化，不过需在结尾加上'\0'结尾字符。在声明字符串时，如果已经设置了初始值，那么字符串
长度可以不用设置。
不过，当没有设置初始值时，就必须设置字符串长度，以便让编译程序知道需要保留多少内存地址给字符串使用。
例如:

    char str[] ="STRING";

或

    char str[7] = {'S','T','R','I','N','G','\0'};

此外，由于字符串不是C++的基本数据类型，所以无法利用数组名直接给另一个字符串变量赋值，如果需要给字符串
变量赋值，必须从字符数组中一个一个取出元素内容进行复制。

  【字符串数组】

字符串是以一维的字符数组来存储的，当有许多关联的字符串集合时，就称为字符串数组，并可以使用二维字符数组来表达。
例如一个班级中所有学生的姓名，每个姓名都有许多字符所组成的字符串，这时就可使用字符串数组来加以存储。
字符串数组声明的方式如下所示：

    char 字符串数组名[字符串数][字符数];

其中字符串数表示的是此字符串数组最多容纳的字符串数目，而字符数表示的是每个字符串最多可容纳多少字符，
并且包含了'\0'结尾字符。当然也可以在声明时就设置初值，不过要记得每个字符串元素都必须包含于双引号之内，
而且每个字符串间要以逗号","分开。
语法格式如下：

    char 字符串数组名[字符串数][字符数]={"字符串常数1","字符串常数2","字符串常数3" ...};

例如以下声明名字为Name的字符串数组，且包含5个字符串，每个字符串包括'\0'字符，长度为10个字节。

    char Name[5][10] = {"John","Mary","Wilson","Candy","Allen"};

字符串数组虽是二维字符数组，在此要输出此Name数组中第二个字符串时，字符串数组的存取则要使用到每个数组中元素的内存地址，
以上述char Name[5][10]的字符串数组来说，要输出第2个字符串时，可以使用以下的指令。

    cout << Name[1];

事实上，使用字符串数组来存储的缺点就是每个字符串长度不会完全相同，而数组又属于静态分配的内存，必须事先声明字符串中的最大长度，
这样操作多少还是会造成内存的浪费。

  【String类】

建立字符串就是要创建一个数据类型为"字符"的数组，如下所示：

    char st1[] = "This is a Test !";

不过如果是先创建数据类型为char的字符数组，然后再指定它的初值，当编译此程序时，会发生错误信息。
不可以直接将字符串常数值赋值给数组。
正确的方法是使用strcpy()函数来指定它的初值。
如果一定要使用这种指定方式将字符串常数值赋值给字符串时，可以使用C++所提供的String类。
在<string>头文件中，不需要引用函数，可以直接运动运算符来进行字符串的处理，像是比较字符串，串接字符串等。
当C语言版本的字符串和C++字符串类混用时，C语言版本的字符串会被自动转化成C++的字符串，但是不允许把C++字符串赋值给C字符串。

C语言版本的字符串声明方法：

    char 字符串名称[长度]；

在上述的程序，可以很清楚地知道字符串到底又几个字符，而String类地字符串，则会自行去计算字符串地字符数，以下是C++字符串的声明方式：

    #include <string> //一定要引入此头文件
    string 字符串名称; //声明一个空的字符串
    string 字符串名称 = "字符串"; //声明设有初始值的字符串格式一
    string 字符串名称("字符串");//声明设有初始值的字符串格式二

  【指针数组】

其他类型的变量都可声明成数组，当然指针也可声明成指针数组，这是结合了静态数据结构与动态数据结构的应用，十分有趣。
其中每个指针数组中的元素都是一个指针变量，而元素值则为指向其他变量的地址值。以下是一维指针数组的声明格式。

    数据类型 *数组名[元素名称];

例如以下是声明一个名称为p的整数指针数组，每个元素(p[i])都可指向一个整数值，另外一个则是声明一个名称为ptr的浮点数指针数组。

    int *p[3];
    float *ptr[4];

一个字符串数组的声明方式如下：

    char name[4][10] = {"Justinian","Momo","Becky","Bush"};

上面的指令将声明一个4x10的数组（包括每个字符串尾包含'\0'字符）。从数组在内存中的排列可知，使用这个方式来声明
字符串数组，缺点是为所声明的数组的每个字符串都必须拥有10个字符类型的内存空间，这是为了满足最长的字符串，对整个存储空间来说
就是一种严重的浪费，因为花费了许多内存空间来存储空字符'\0'。
为了避免内存空间的浪费，使用"指针数组"来存储字符串就相当适合，可以将之前的声明更改为以下方式。

    char *name[4]={"Justinian","Momo","Becky","Bush"};

在这个声明中，每个数组元素name[i]都是用来存储内存的地址，它们分别存储了指向字符串的内存地址，
而编译程序会自动分配正好够的字符空间来存储对应的字符串，因此就不会浪费内存的空间来存储无用的空字符。

  【稀疏矩阵】

  稀疏矩阵：如果一个矩阵中的大部分元素为零的话，就可以称为稀疏矩阵。
  对于稀疏矩阵而言，实际存储的数据项很少，如果在计算机中使用传统的二维数组方式来存储稀疏矩阵，
  就会十分浪费计算机的存储空间。特别是当矩阵很大时，例如存储一个1000x1000的稀疏矩阵所需的空间需求，
  而大部分的元素都是零的话，这样空间的利用率确实不经济。

  而提高内存空间利用率的方法就是利用三项式(3-tuple)的数据结构。把每一个非零项以(i,j,item-value)来表示，
  就是假如一个稀疏矩阵有n个非零项，那么可以利用一个A(0:n,1:3)的二维数组来存储这些非零项，把这样存储的矩阵称为
  压缩矩阵。
  其中A(0,1)存储这个稀疏矩阵的行数，A(0,2)存储这个稀疏矩阵的列数，而A(0,3)则是此稀疏矩阵非零项
  的总数。另外，每一个非零项以(i,j,item-value)来表示。其中i为此矩阵非零项所在的行数,j为此矩阵
  非零的值。

    A(0,1) => 表示此矩阵的行数
    A(0,2) => 表示此矩阵的列数
    A(0,3) => 表示此矩阵非零项的总数
  
  稀疏矩阵的转置：

  直接将稀疏矩阵进行转置，只需要使用两个for循环，所以时间复杂度可以视为O(columns*rows)。
  如果说使用一个用三项式存储的压缩矩阵，它首先会确定原稀疏矩阵中每一列的元素个数。
  根据这个原因，就可以实现确定转置矩阵中每一行的起始位置，接着再将原稀疏矩阵中的元素一个个地
  放到在转置矩阵中的正确位置。这样的做法可以将时间复杂度调整到O(columns+rows)。

  【上三角形矩阵】

  上三角形矩阵(upper triangular matrix)就是一种对角线以下元素都为0的n*n矩阵。其中又可以分为右上三角形矩阵
  (right upper triangular matrix)与左上三角形矩阵(left upper triangular matrix)。
  由于上三角形矩阵仍有许多元素为0，为了避免浪费存储空间，可以把三角形矩阵的二维模式，存储在一维数组中。
  
  【多维数组】

  在进行程序设计时，只要目标计算机的内存大小许可，就可以声明更多维的数组来存取数据，二维以上的数组
  都被称为多维数组。
  在实际的计算机内存中无法以立方体的方式来存储，其实仍然是以线性方式来存储数组的，都可视为是一维数组的扩展。

  按照不同的语言，区分为两种方式：

  1.以行为主(row-major):使用转换公式来计算A(i,j,k)排列在第几位。首先可以将数组A视为u1个u2*u3的二维数组，再将
  每个二维数组视为有u2个一维数组，每一个一维数组可包含u3个元素。假定每个元素有d个单位空间，且a为数组的起始
  地址。

  根据上面的分析可以得到以下地址计算公式：

     Loc(A(i,j,k)) = a + (i-1)u2u3d + (j-1)u3d + (k-1)d

  2.以列为主(Column-major):同样的，可以直观地将数组A视为u3个u2*u1的二维数组，再将每个二维数组视为有
  u2个一维数组，每一个一维数组含有u1个元素。假定每个元素有d单位空间，且a为起始地址。
  根据上面的分析可以得到aijk元素的地址计算公式：

     Loc(A(aijk)) = a + (k-1)u2u1d + (j-1)u1d + (i-1)d
  
  总结：如果是把数组A声明为A(l1:u1,l2:u2,l3:u3)的标注表示法，且对任意aijk，有u1>=i>=l1,u2>=j>=l2,u3>=k>=l3,
  则m=(u1-l1+1),n=(u2-l2+1),o=(u3-l3+1),这样我们可以将数组A视为m个二维数组，再将每个二维数组视为有n个一维数组，
  每一个一维数组含有o个元素，则aijk的地址计算公式如下：

1)以行为主(Row-major):

     Loc(A(aijk)) = a + (i-l1)nod + (j-l2)od + (k-l3)d

2)以列为主(Column-major):

     Loc(A(aijk)) = a + (k-l3)mnd + (j-l2)md + (i-l1)d
  
