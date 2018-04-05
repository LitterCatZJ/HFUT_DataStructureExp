#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>

#include "tree.h"
#include "./include/BinaryTree.h"
#include "queues.h"
using namespace std;

const int TINY=100;
const int SMALL=5000;
const int MEDI=10000;
const int LARGE=100000;

void quick_sort(int a[],int lo,int hi);//��������
int partition_n(int a[],int lo,int hi);//�з�Ԫ��
void shell_sort(int *a,int n,int s);//ϣ������
void insert_sort(int a[],int n);
void adjust_three(int a[],int lo,int hi);//����Ԫ�ذ�ģ3��������
//���й��㷨
void sink(int a[],int n,int k);
void heap_sort(int a[],int n);
void heap_sort_show(int a[],int n);
void show_array(int a[],int n);
//�ļ����
void generate_filedata();
void get_data_from_file(string name,int a[]);
void get_data_from_file(string ,vector<int>& a);

int main()
{
    //generate_filedata();
    //int a[]={4,5,6,7,1,76,9,32};
    //quick_sort(a,0,sizeof(a)/sizeof(a[0]));
    //shell_sort(a,sizeof(a)/sizeof(a[0]));
    //adjust_three(a,0,sizeof(a)/sizeof(a[0])-1);
    //heap_sort(a,sizeof(a)/sizeof(a[0])-1);
    //for(int i=0;i<sizeof(a)/sizeof(a[0]);i++) cout<<a[i]<<' ';
    //cout<<endl;

//    (1) ���ò�ͬʵ���������۲���������ʵ���бȽϺͽ���Ԫ�صĴ�����
//    ���������ݵĹ�ģ�ͳ�ʼ������Ƚ��뽻������֮��ĺ�����ϵ��

    cout<<"(1) ���ò�ͬʵ���������۲���������ʵ���бȽϺͽ���Ԫ�صĴ�����"<<endl
        <<"���������ݵĹ�ģ�ͳ�ʼ������Ƚ��뽻������֮��ĺ�����ϵ��"	<<endl;
    int a1[TINY],a2[SMALL],a3[MEDI],a4[LARGE];
    for(int i=1;i<=4;i++)
    {
        string filename1,filename2;
        int *p,size;
        if(i==1) {
            filename1="./tiny.txt";
            filename2="./tiny2.txt";
            p=a1;
            size=TINY;
        }
        else if(i==2){
            filename1="./small.txt";
            filename2="./small2.txt";
            p=a2;
            size=SMALL;
        }
        else if(i==3){
            filename1="./meddle.txt";
            filename2="./meddle2.txt";
            p=a3;
            size=MEDI;
        }
        else if(i==4){
            filename1="./large.txt";
            filename2="./large2.txt";
            p=a4;
            size=LARGE;
        }
        cout<<'('<<i<<')'<<"���ݹ�ģ��"<<size<<endl;
        cout<<"����ʱ��(ms)��";
        for(int i=1;i<=2;i++)
        {
            if(i==1) cout<<"\tԪ�����:";
            else cout<<"\tԪ��ȫ���ظ�:";
            long optime=clock();
            string file;
            if(i==1) file=filename1;
            else file=filename2;
            get_data_from_file(file,p);
            quick_sort(p,0,size);
            long edtime=clock();
            cout<<edtime-optime<<"\t";
        }
        cout<<endl;

    }
    cout<<endl;
    //(2)������湦��:��һ�������������Ϊ���������飺���У��ı���������ߣ�
    //���г��ԣ��ࣱ�������м䣬�����г��ԣ��ࣲ���������ұߡ�Ҫ���㷨��ʱ�価�����١�
    cout<<"(2) ������湦�ܣ���һ�������������Ϊ���������飺���У��ı���������ߣ�"<<endl
        <<"���г��ԣ��ࣱ�������м䣬�����г��ԣ��ࣲ���������ұߡ�Ҫ���㷨��ʱ�価�����١�"<<endl;
    int b1[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
    int b2[]={11,12,13,14,15,1,2,3,4,5,6, 10, 16, 1,22,23,2,17,18,19,20,24, 7,8,9,25,26};
    int b3[]={5,6,7, 1,2,3,4,8,9,10,11,12,13, 16,17,18, 14, 25,26,15,19,20,21,22,23,24};
    int n;
    cout<<"��һ�����ݣ�"<<endl;
    n=sizeof(b1)/sizeof(b1[0]);
    for(int i=0;i<n;i++) cout<<b1[i]<<' ';
    cout<<endl;
    adjust_three(b1,0,n);
    cout<<"������"<<endl;
    for(int i=0;i<n;i++) cout<<b1[i]<<' ';
    cout<<endl;

    cout<<"�ڶ������ݣ�"<<endl;
    n=sizeof(b2)/sizeof(b2[0]);
    for(int i=0;i<n;i++) cout<<b2[i]<<' ';
    cout<<endl;
    adjust_three(b2,0,n);
    cout<<"������"<<endl;
    for(int i=0;i<n;i++) cout<<b2[i]<<' ';
    cout<<endl;

    cout<<"���������ݣ�"<<endl;
    n=sizeof(b3)/sizeof(b3[0]);
    for(int i=0;i<n;i++) cout<<b3[i]<<' ';
    cout<<endl;
    adjust_three(b3,0,n);
    cout<<"������"<<endl;
    for(int i=0;i<n;i++) cout<<b3[i]<<' ';
    cout<<endl;
    cout<<endl;
    //(3) ʵ��shell�����㷨�����۲��ڲ��ò�ͬ�Ĳ���ѡȡ������������������ݵıȽϺ��ƶ�������Ӱ�졣
    cout<<"(3) ʵ��shell�����㷨�����۲��ڲ��ò�ͬ�Ĳ���ѡȡ������������������ݵıȽϺ��ƶ�������Ӱ�졣"<<endl;
    get_data_from_file("./large.txt",a4);
    n=sizeof(a4)/sizeof(a4[0]);
//    cout<<"��������ʱ��(ms):";
//    long op=clock();
//    insert_sort(a4,sizeof(a4)/sizeof(a4[0]));
//    long ed=clock();
//    cout<<ed-op<<endl;
//    random_shuffle(a4,a4+n);
    for(int i=6;i>=2;i--)
    {
        cout<<"������h=h*"<<i<<"+1:"<<endl;
        long optime=clock();
        shell_sort(a4,sizeof(a4)/sizeof(a4[0]),i);
        long edtime=clock();
        cout<<"����ʱ��(ms):"<<edtime-optime<<endl;
        random_shuffle(a4,a4+sizeof(a4)/sizeof(a4[0]));
    }

    //(4) ����㷨ʵ������ѡ������Ҫ�����������������ʾ������̣��������ر�ʾ��������̡�
    cout<<"(4) ����㷨ʵ������ѡ������Ҫ�����������������ʾ������̣��������ر�ʾ��������̡�"<<endl;

    std::vector<int> L = {49, 38, 65, 97, 76, 13, 27, 49};
    BinaryTreeNode* tree = buildTree(buildList(L), L.size());

    std::cout << "Begin : " << std::endl;
    printTree(tree); std::cout << std::endl;

    std::vector<int> result;
    for (std::size_t i=0; i<L.size(); ++i)
    {
        int value = rebuildTree (tree);
        std::cout << "Round[" << i+1 << "] : " << std::endl;
        printTree(tree); std::cout << std::endl;
        result.push_back(value);
    }

    std::cout << "result : ";
    for (std::size_t i=0; i<L.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    //(4) ����㷨ʵ������ѡ������Ҫ�����������������ʾ������̣��������ر�ʾ��������̡�
    cout<<"(5)������Ͷ�������ʽ��̬��ʾ�������㷨��������̡�"<<endl;
    int b5[]={0,1,2,106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,808,923,25};
    heap_sort_show(b5,sizeof(b5)/sizeof(b5[0]));
    //heap_sort(b5,sizeof(b5)/sizeof(b5[0]));
    //show_array(b5,sizeof(b5)/sizeof(b5[0]));
    cout<<endl;

    cout<<"����ʽ��������ķ���ʵ�ֶ�����������ÿ��Ԫ�����Ϊ��λ��������"<<endl;
    Queue oldque;
    int b6[]={106,213,325,446,579,654,721,870,917,510,21,632,73,14,815,316,412,18,619,720,21,808,923,25,26};
    for(int i=0;i<sizeof(b6)/sizeof(b6[0]);i++)
        oldque.push(b6[i]);
    oldque.RadixSort(oldque);




    return 0;
}

void quick_sort(int a[],int lo,int hi)
{
    if(hi<=lo) return;
    int j=partition_n(a,lo,hi);
    quick_sort(a,lo,j-1);
    quick_sort(a,j+1,hi);
}

int partition_n(int a[],int lo,int hi)
{
    int i=lo,j=hi+1;
    int v=a[lo];
    while(true)
    {
        while(a[++i]<v) continue;
        while(v<a[--j]) continue;
        if(i>=j) break;
        swap(a[i],a[j]);
    }
    swap(a[lo],a[j]);
    return j;
}

void shell_sort(int a[],int n,int s)
{
    int h=1;
    while(h<n/s) h=s*h+1;//1,4,13,40,121...
    while(h>=1)
    {
        for(int i=h;i<n;i++)
        {
            for(int j=i;j>=h&&a[j]<a[j-h];j-=h)
                swap(a[j],a[j-h]);
        }
        h=h/s;
    }
}
void insert_sort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0&&a[j]<a[j-1];j--)
            swap(a[j],a[j-1]);
    }
}
void adjust_three(int a[],int lo,int hi)
{
    if(hi<=lo) return;
    int lt=lo,i=lo+1,gt=hi;
    while(i<=gt)
    {
        int cmp=a[i]%3;
        if(cmp==0) swap(a[lt++],a[i++]);
        else if(cmp==2) swap(a[i],a[gt--]);
        else i++;
    }
}

void sink(int a[],int n,int k)
{
    while(2*k<=n)
    {
        int j=2*k;
        if(j<n&&a[j]<a[j+1]) j++;
        if(a[k]>a[j]) break;
        swap(a[k],a[j]);
        k=j;
    }
}
void heap_sort(int a[],int n)
{
    for(int k=n/2;k>=1;k--)
        sink(a,n,k);
    while(n>1)
    {
        swap(a[1],a[n--]);
        sink(a,n,1);
    }
}
void show_array(int a[],int n)
{
    for(int i=1;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;
}
void heap_sort_show(int a[],int n)
{
    cout<<"���ݣ�";
    for(int i=1;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;
    cout<<"��������:";
    for(int k=n/2;k>=1;k--)
        sink(a,n,k);
    for(int i=1;i<n;i++) cout<<a[i]<<' ';
    cout<<endl;
    BinaryTree tree;
    tree.set_elements(a,n);
    //tree.print_by_level();
    tree.print_by_level();
    cout<<endl;
    cout<<"������̣�"<<endl;
    int m=n;
    while(n>1)
    {
        swap(a[1],a[n--]);
        sink(a,n,1);
        if(n>=2){
        tree.set_elements(a,n);
        tree.print_by_level();
        }
        cout<<endl;
        cout<<"��������:";
        show_array(a,m);
    }
}

void get_data_from_file(string name,int a[])
{
    ifstream fin(name);
    if(fin.fail()) { cout<<"open file error";return;}
    int ct=0;
    while(!fin.eof())
    {
        fin>>a[ct++];
    }
}
void get_data_from_file(string name,vector<int>& a)
{
    ifstream fin(name);
    if(fin.fail()) { cout<<"open file error";return;}
    int ct=0;int tp;
    while(!fin.eof())
    {
        fin>>tp;
        a.push_back(tp);
    }
}
void generate_filedata()
{
    ofstream fout;
    fout.open("./small.txt",ios_base::out);
    if(fout.fail()) {cout<<"open file error"<<endl;return;}
    vector<int> tmp;
    int tp=1;
    for(int i=0;i<SMALL;i++) {
        fout<<3<<' ';
        tp++;
        if(tp%20==0) fout<<endl;
        //tmp.push_back(i);
    }

//    random_shuffle(tmp.begin(),tmp.end());
//
//    for(int x : tmp)
//    {
//        fout<<x<<' ';
//        tp++;
//        if(tp%20==0) fout<<endl;
//    }
}
