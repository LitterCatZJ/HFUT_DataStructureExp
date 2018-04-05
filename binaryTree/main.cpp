#include<iostream>
#include "BinaryTree.h"

//#define BIN_EXP

using namespace std;
void binary_exp();
void bin_sort_exp();
int bin_search(int a[],int n,int x);

int main()
{
    #ifdef BIN_EXP
    binary_exp();
    #else
    bin_sort_exp();
    #endif // BIN_EXP
    return 0;
}

int bin_search(int a[],int n,int key)
{
    int lo=0,hi=n-1;
    while(lo<=hi)
    {
        int mid=(lo+hi)/2;
        if(key<a[mid]) hi=mid-1;
        else if(key>a[mid]) lo=mid+1;
        else return mid;
    }
    return -1;
}
void bin_sort_exp()
{
    //(1) ���������ݱ��ֱ���ö��ֲ����㷨ʵ�ֲ��ң�
    //�������ҹ����������Ƚϵ�Ԫ�أ����±꣩�����Զ��ֲ��ҵ��ж��������͡�
    int a1[]={1,2,3,4,6,7,8,9,10,11,12,13,17,18,19,20,24,25,26,30,35,40,45,50,100};
    int a2[]={2,3,5,7,8,10,12,15,18,20,22,25,30,35,40,45,50,55,60,80,100};
    int e1[]={2,8,20,30,50,5,15,33,110 };
    int e2[]={22,8,80,3,100,1,13,120};
    cout<<"(1)���ֲ���"<<endl;
    cout<<"��һ������:";
    for(int i=0;i<sizeof(a1)/sizeof(a1[0]);i++) cout<<a1[i]<<' ';
    cout<<endl;
    for(int i=0;i<sizeof(e1)/sizeof(e1[0]);i++)
    {
        cout<<e1[i]<<": "<<bin_search(a1,sizeof(a1)/sizeof(a1[0]),e1[i])<<endl;
    }
    cout<<endl;
    cout<<"�ڶ�������:";
    for(int i=0;i<sizeof(a2)/sizeof(a2[0]);i++) cout<<a2[i]<<' ';
    cout<<endl;
    for(int i=0;i<sizeof(e2)/sizeof(e2[0]);i++)
    {
        cout<<e2[i]<<": "<<bin_search(a2,sizeof(a2)/sizeof(a2[0]),e2[i])<<endl;
    }
    cout<<endl;
    //�����ʵ��Ͷ����������йأ�����������ʵ��
    //(2) ��Ƴ��ڶ����������в�������㷨���ڴ˻�����ʵ�ֹ����������������㷨��
    cout<<"(2) ��Ƴ��ڶ����������в�������㷨���ڴ˻�����ʵ�ֹ����������������㷨��"<<endl;
    int a3[]={100,150,120,50,70,60,80,170,180,160,110,30,40,35,175};
    int a4[]={100,70,60,80,150,120,50,160,30,40,170,180,175,35};
    BinaryTree st1(a3,sizeof(a3)/sizeof(a3[0]));
    BinaryTree st2(a4,sizeof(a4)/sizeof(a4[0]));
    cout<<"��һ�����ݣ�"<<endl;
    st1.print(2);
    cout<<"�ڶ������ݣ�"<<endl;
    st2.print(2);
    cout<<endl;
    //(3) ����㷨�ڶ����������в���ָ��ֵ�Ľ�㡣
    cout<<"(3) ����㷨�ڶ����������в���ָ��ֵ�Ľ�㡣"<<endl;
    int e3[]={150,70,160,190,10,55,175 };
    for(int i=0;i<sizeof(e3)/sizeof(e3[0]);i++)
        st1.search(e3[i]);
    cout<<endl;
    //(4) ����㷨�ڶ�����������ɾ���ض�ֵ�Ľ�㡣
    cout<<"(4) ����㷨�ڶ�����������ɾ���ض�ֵ�Ľ��."<<endl;
    cout<<"ɾ��ǰ��";st1.print(2);
    cout<<"ɾ��30��";st1.remove(30); st1.print(2);
    cout<<"ɾ��150��";st1.remove(150); st1.print(2);
    cout<<"ɾ��100: ";st1.remove(100); st1.print(2);
    cout<<endl;
    //(5) ��֪��������A[1..26]������������㷨�Թ���һ��ƽ��Ķ�������������Ÿ������е�����Ԫ�ء�
    cout<<"(5) ��֪��������A[1..26]������������㷨�Թ���һ��ƽ��Ķ�������������Ÿ������е�����Ԫ�ء�"<<endl;
    int a5[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    int a6[]={1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,277,302,328};
    BinaryTree avl_st1(a5,sizeof(a5)/sizeof(a5[0]),true);
    BinaryTree avl_st2(a6,sizeof(a6)/sizeof(a6[0]),true);
    cout<<"��һ�����ݣ�"<<endl;
    avl_st1.print_by_level();
    cout<<endl;
    cout<<"�ڶ������ݣ�"<<endl;
    avl_st2.print_by_level();
    cout<<endl<<endl;
    //

    cout<<"���"<<endl;

}
void binary_exp()
{
    BinaryTree tree1("./btr151.txt");
    BinaryTree tree2("./btr21.txt");
//    <1>��ӡ�������������ֱ�����
//    ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt151.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<1>��ӡ�������������ֱ�����"<<endl;
    for(int i=1;i<=2;i++)
    {
        cout<<"��"<<i<<"�����ݣ�"<<endl;
        cout<<"�������򣬺���������"<<endl;
        if(i==1){
            tree1.print(1);
            tree1.print(2);
            tree1.print(3);
        }
        else{
            tree2.print(1);
            tree2.print(2);
            tree2.print(3);
        }
    }
//    <2>����㷨�������������������и�����ֵ��������Ӧ�Ĳ������
    cout<<endl;
    cout<<"<2>����㷨�������������������и�����ֵ��������Ӧ�Ĳ������"<<endl;
    cout<<"��һ������bt151.btr��"<<endl;
    tree1.inorder_and_level();
    cout<<"�ڶ�������bt21.btr��"<<endl;
    tree2.inorder_and_level();
    cout<<endl;
//    <3>��������ĸ߶ȡ�
//	ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt261.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<3>��������ĸ߶ȡ�"<<endl;
    BinaryTree tree3("./btr261.txt");
    cout<<"��һ�����ݣ� bt261.btr"<<endl;
    cout<<tree3.height()<<endl;
    cout<<"�ڶ������ݣ� bt21.btr"<<endl;
    cout<<tree2.height()<<endl;

    cout<<endl;
//    <4>��������Ľ������
//    ��һ�����ݣ� bt261.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<4>��������Ľ������"<<endl;
    cout<<"��һ�����ݣ� bt261.btr: "<<tree3.count()<<endl;
    cout<<"�ڶ������ݣ� bt21.btr: "<<tree2.count()<<endl;

    cout<<endl;
//    <5>���������Ҷ�ӽ������
//	ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt261.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<5>���������Ҷ�ӽ������"<<endl;
    cout<<"��һ�����ݣ�bt261.btr: "<<tree3.leaves()<<endl;
    cout<<"�ڶ������ݣ�bt21.btr: "<<tree2.leaves()<<endl;
    cout<<endl;

//    <6>��������Ķ�Ϊ2�Ľ������
//	ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt261.btr
//    �ڶ������ݣ� bt21.btr

    cout<<"<6>��������Ķ�Ϊ2�Ľ������"<<endl;
    cout<<"��һ�����ݣ� bt261.btr: "<<tree3.two_degree_nodes()<<endl;
    cout<<"�ڶ������ݣ� bt21.btr: "<<tree2.two_degree_nodes()<<endl;
    cout<<endl;

//    <7>��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��������ʱ������Ӧ��ʾ��Ϣ��
//    ���ֵܽ��ͺ��ӽ�㣬����ʱҪ��ȷָ�������ֵܡ����ӡ����ֵܻ��Һ��ӡ�
//	ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt31.btr
//    �ڶ������ݣ� bt21.btr

    BinaryTree tree4("./btr31.txt");
    cout<<"<7>��������һ��Ԫ��x�����丸�ڵ㡢�ֵܽ�㡢�ӽ���ֵ��������ʱ������Ӧ��ʾ��Ϣ��"<<endl;
    cout<<"��һ�����ݣ� bt31.btr:"<<endl;
    cout<<"����һ�����е��ַ���";
    char t;cin>>t;
    tree4.about_x(t);
    cout<<endl<<endl;
    cout<<"�ڶ������ݣ� bt21.btr"<<endl;
    cout<<"����һ���ַ���";cin>>t;
    tree2.about_x(t);
    cout<<endl<<endl;

//    <8>��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ��
//	ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt26.btr
//    �ڶ������ݣ� bt21.btr
    BinaryTree tree5("./btr26.txt");
    cout<<"<8>��������һ��Ԫ��x�����������еĲ�Ρ�������ʱ������Ӧ��ʾ��Ϣ��"<<endl;
    cout<<"��һ�����ݣ�"<<endl;
    cout<<"����һ��Ԫ�أ�";cin>>t;
    cout<<"����Ϊ��"<<tree5.find_level(t)<<endl;
    cout<<"�ڶ������ݣ�"<<endl;
    cout<<"����һ��Ԫ�أ�";cin>>t;
    cout<<"����Ϊ:"<<tree2.find_level(t)<<endl;
    cout<<endl;

//    <9>����˳��ʽ�洢�������еĶ�����ת��Ϊ����������ʽ����������Ҫ��չΪ��ȫ����������
//	ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt8.btr
//    �ڶ������ݣ� bt14.btr



//<10>������������ÿ���������Һ���ָ���ֵ����������������Ϊ����������������Ϊ����������
//	ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt151.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<10>������������ÿ���������Һ���ָ���ֵ��"<<endl;
    cout<<"��һ�����ݣ� bt151.btr:"<<endl;
    BinaryTree tree6("./btr151.txt");
    tree6.print(2);
    tree6.change_right_left();
    tree6.print(2);
    cout<<"�ڶ������ݣ� bt21.btr: "<<endl;
    tree2.print(2);
    tree2.change_right_left();
    tree2.print(2);
    cout<<endl;


    cout<<"ѡ��ʵ��"<<endl;
//    <11>����һ�ö�����T��T1��
//	ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ� bt151.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<11>����һ�ö�����T��T1��"<<endl;
    cout<<"��һ�����ݣ� bt151.btr"<<endl;
    BinaryTree tree62(tree6);
    tree62.print(1);
    cout<<"�ڶ������ݣ�bt21.btr"<<endl;
    BinaryTree tree22(tree2);
    tree22.print(1);
    cout<<endl;
//    <12>�����������ÿ��Ҷ�ӽ�㵽������·���������Ľ�㣩��
//    ��һ�����ݣ� bt261.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<12>�����������ÿ��Ҷ�ӽ�㵽������·���������Ľ�㣩��"<<endl;
    cout<<"��һ�����ݣ� bt261.btr"<<endl;
    tree3.leaves2root();
    cout<<"�ڶ������ݣ� bt21.btr"<<endl;
    tree2.change_right_left();
    tree2.leaves2root();
    cout<<endl;

//    <13>�Զ��������ʾ�Ķ������������ϵ��£������Ҵ�ӡ���ֵ��
//    ������δ�ӡ������ʾ����Ҫʹ�ö��У�
//    ��һ�����ݣ� bt261.btr
//    �ڶ������ݣ� bt21.btr

    cout<<"<13>�Զ��������ʾ�Ķ�����,����δ�ӡ�ڵ�"<<endl;
    cout<<"��һ�����ݣ� bt261.btr"<<endl;
    tree3.print_by_level();
    cout<<"�ڶ������ݣ� bt21.btr"<<endl;
    tree2.print_by_level();
    cout<<endl;

//    <14>�Զ��������ʾ�Ķ���������2���������Ĺ�ͬ���ȡ�
//    ��һ�����ݣ� bt261.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<14>�Զ��������ʾ�Ķ���������2���������Ĺ�ͬ���ȡ�"<<endl;
    cout<<"��һ�����ݣ� bt261.btr"<<endl;
    cout<<tree3.near_common_ancestor('l','e')<<endl;
    cout<<"�ڶ������ݣ� bt21.btr"<<endl;
    cout<<tree2.near_common_ancestor('u','m')<<endl;
    cout<<endl;

//    <15>���������һ�����·�����ȣ��������������·���ϵĸ����ֵ��
//    ��һ�����ݣ� bt261.btr
//    �ڶ������ݣ� bt21.btr
    cout<<"<15>���������һ�����·�����ȣ��������������·���ϵĸ����ֵ��"<<endl;
    cout<<"��һ�����ݣ� bt261.btr"<<endl;
    tree3.leaves2root(true);
    cout<<"�ڶ������ݣ� bt21.btr"<<endl;
    tree2.leaves2root(true);
    cout<<endl;


}
