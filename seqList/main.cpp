/**
 *Copyright:
 *This code is free software; you can redistribute it and/or modify
 *it under the terms of the GPL-3.0
 *
 * @author zhangjian
 * @date 2017.11
 *
 */

///////////////////////////////////////////////////////////////////////

#include "SeqList.h"
#include<iostream>
#include<algorithm>
using namespace std;
void ListMerge(SeqList A,SeqList B,SeqList * pC);
void insert(SeqList*,Type x);
void seperate(SeqList& a,SeqList& b,SeqList& c);
void common(SeqList& a,SeqList& b,SeqList& c);
int removeDuplicateEle(SeqList& a);
bool subset(SeqList *A,SeqList *B);
void mergeList(SeqList &a, SeqList& b);
void mergeSets(SeqList& a,SeqList& b,SeqList& );

int M_Search(int A[], int B[], int n);

int main()
{


    int a[]={1,2,3,4,5,6,7,8,9,10,33,2,5,90};
    SeqList c(a,14);
    //<1>��˳����е�i��Ԫ�أ����������������ڣ�����
    //��һ�����ݣ�˳�����n��10��i�ֱ�Ϊ5��n��0��n+1��n+2
    //�ڶ������ݣ�˳�����n=0��i�ֱ�Ϊ0��2
    cout<<"<1>��˳����е�i��Ԫ�أ����������������ڣ�����"<<endl;
    c.showSeqList();
    int e[]={5,14,0,15,16};
    int x;
    for(int i=0;i<5;i++)
    {
        if(c.getElement(e[i],x)) cout<<e[i]<<"��Ӧ��Ԫ��Ϊ��"<<x<<endl;
        else cout<<e[i]<<"������Ԫ�ز�����"<<endl;
    }

    cout<<endl;
    c.clearSeqList();
    c.showSeqList();
    if(c.getElement(0,x)) cout<<0<<"��Ӧ��Ԫ��Ϊ��"<<x<<endl;
    else cout<<0<<"������Ԫ�ز�����"<<endl;

    if(c.getElement(2,x)) cout<<2<<"��Ӧ��Ԫ��Ϊ��"<<x<<endl;
    else cout<<2<<"������Ԫ�ز�����"<<endl;


//    <2>�ڵ�i�����ǰ����ֵΪx�Ľ�㡣
//    ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ�˳�����n��10��x=100,  i�ֱ�Ϊ5,n,n+1,0,1,n+2
//    �ڶ������ݣ�˳�����n=0��x=100��i=5
    cout<<endl<<"<2>�ڵ�i�����ǰ����ֵΪx�Ľ�㡣"<<endl;
    SeqList s(a,14);
    s.showSeqList();
    x=100;
    for(int i=0;i<5;i++)
    {
        if(s.listInsert(e[i],x)){
            cout<<"������"<<e[i]<<"���ɹ�����"<<x<<endl;
            s.showSeqList();
        }
        else cout<<"��"<<e[i]<<"����ʧ��"<<endl;
    }

//    <3>ɾ��˳����е�i��Ԫ�ؽ�㡣
//    ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ�˳�����n��10��i�ֱ�Ϊ5,n,1,n+1,0
//    �ڶ������ݣ�˳�����n=0�� i=5
    cout<<endl<<"<3>ɾ��˳����е�i��Ԫ�ؽ�㡣"<<endl;
    s.showSeqList();
    for(int i=0;i<5;i++)
    {
        if(s.listDelete(e[i])) {
            cout<<"������"<<e[i]<<"ɾ���ɹ�"<<endl;
            s.showSeqList();
        }
        else cout<<"������"<<e[i]<<"ɾ��ʧ��"<<endl;
    }


//    <4>��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ�������������������ԡ�
//    ʵ��������ݻ���Ҫ��
//    ˳���Ԫ��Ϊ ��10,20,30,40,50,60,70,80,90,100��,
//    x�ֱ�Ϊ25��85��110��8
    cout<<endl<<"<4>��һ�����������˳���L�в���һ��ֵΪx��Ԫ�أ��������������������"<<endl;
    int b[]={10,20,30,40,50,60,70,80,90,100};
    s.reCtor(b,10);
    s.showSeqList();
    int t[]={25,85,110,8};
    for(int i=0;i<4;i++)
    {
        insert(&s,t[i]);
        cout<<"����"<<t[i]<<":"<<endl;
        s.showSeqList();
    }

//    <5>��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳����У�
//    Ȼ��ԭ����±�Ԫ��ͬʱ�������Ļ�ϣ��Ա�����������
//    ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ�˳���Ԫ��Ϊ ��1,2,3,4,5,6,7,8,9,10,20,30,40,50,60��
//    �ڶ������ݣ�˳���Ԫ��Ϊ ��10,20,30,40,50,60,70,80,90,100��
    cout<<endl<<"<5>��˳�����е��������ż������ֽ⿪��Ԫ��ֵΪ������ż�������ֱ�����µ�˳�����"<<endl;
    int m1[]={1,2,3,4,5,6,7,8,9,10,20,30,40,50,60};
    int m2[]={10,20,30,40,50,60,70,80,90,100};
    SeqList n;
    for(int i=0;i<2;i++)
    {
        cout<<"��"<<i+1<<"�����ݣ�"<<endl;
        if(i==0){
            s.reCtor(m1,sizeof(m1)/sizeof(m1[0]));
        }
        else  s.reCtor(m2,sizeof(m2)/sizeof(m2[0]));

        s.showSeqList();
        c.clearSeqList();
        n.clearSeqList();
        seperate(s,c,n);
        c.showSeqList();
        n.showSeqList();
        cout<<endl;
    }


//    <6>��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3�С�
//    ʵ��������ݻ���Ҫ��
//    ��һ��
//    ��һ��˳���Ԫ��Ϊ ��1��3��6��10��15��16��17��18��19��20��
//    �ڶ���˳���Ԫ��Ϊ ��1��2��3��4��5��6��7��8��9��10��18��20��30��
//    �ڶ���
//    ��һ��˳���Ԫ��Ϊ ��1��3��6��10��15��16��17��18��19��20��
//    �ڶ���˳���Ԫ��Ϊ ��2��4��5��7��8��9��12��22��
//    ������
//    ��һ��˳���Ԫ��Ϊ ����
//    �ڶ���˳���Ԫ��Ϊ ��1��2��3��4��5��6��7��8��9��10��

    cout<<endl<<"<6>��������������˳���L1��L2�еĹ���Ԫ�أ������µ�˳���L3��"<<endl;
    int p1[]={1,3,6,10,15,16,17,18,19,20};
    int p2[]={1,2,3,4,5,6,7,8,9,10,18,20,};
    int p3[]={2,4,5,7,8,9,12,22};
    int p4[]={1,2,3,4,5,6,7,8,9,10};

    for(int i=0;i<3;i++)
    {
        cout<<"��"<<i+1<<"��Ԫ�أ�"<<endl;
        if(i==0) {
            s.reCtor(p1,sizeof(p1)/sizeof(p1[0]));
            c.reCtor(p2,sizeof(p2)/sizeof(p2[0]));
        }
        else if(i==1){
            s.reCtor(p1,sizeof(p1)/sizeof(p1[0]));
            c.reCtor(p3,sizeof(p3)/sizeof(p3[0]));
        }
        else{
            s.clearSeqList();
            c.reCtor(p4,sizeof(p4)/sizeof(p4[0]));
        }
        s.showSeqList();
        c.showSeqList();
        n.clearSeqList();
        common(s,c,n);
        cout<<"����Ԫ��Ϊ��"<<endl;
        n.showSeqList();
        cout<<endl;

    }

//    <7>ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ��������á�
//    ʵ��������ݻ���Ҫ��
//    ��һ�����ݣ�˳���Ԫ��Ϊ ��1,2,3,4,5,6,7,8,9��
//    �ڶ������ݣ�˳���Ԫ��Ϊ ��1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9��
//    ���������ݣ�˳���Ԫ��Ϊ ��1,2,3,4,5,5,6,7,8,8,9,9,9,9,9��

    cout<<endl
        <<"<7>ɾ����������˳����е��ظ�Ԫ�أ���ͳ���ƶ�Ԫ�ش�����Ҫ��ʱ��������á�"<<endl;
    int p5[]={1,2,3,4,5,6,7,8,9};
    int p6[]={1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,9};
    int p7[]={1,2,3,4,5,5,6,7,8,8,9,9,9,9,9};
    for(int i=0;i<3;i++) {
        cout<<"��"<<i+1<<"�����ݣ�"<<endl;
        if(i==0)s.reCtor(p5,sizeof(p5)/sizeof(p5[0]));
        else if(i==1) s.reCtor(p6,sizeof(p6)/sizeof(p6[0]));
        else s.reCtor(p7,sizeof(p7)/sizeof(p7[0]));

        s.showSeqList();
        cout<<"�ƶ�������"<<removeDuplicateEle(s)<<endl;
        s.showSeqList();
    }


//    1.4* ˳�����չʵ��
//    �Ǳ������ݣ�����Ȥ��ͬѧѡ����
//    <1> ��������˳���L1��L2����2����кϲ�����ʹ�úϲ����Ϊһ�����ϣ����ϵ�Ԫ�طŻ�L1���б��棬Ҫ��ʱ��������á�
//    <2>����������˳����ʾ����A��B��ʵ�֣�
//    C=A?B��C=A?B��C=A-B
//    A=A?B��A=A?B��A=A-B
//    <3>����������˳����ʾ����A��B���ж�A�Ƿ�B���Ӽ���

    cout<<endl;
    cout<<"1.4* ˳�����չʵ��"<<endl;
    cout<<"<1> ��������˳���L1��L2����2����кϲ�����ʹ�úϲ����Ϊһ�����ϣ�"<<endl
        <<"���ϵ�Ԫ�طŻ�L1���б��棬Ҫ��ʱ��������á�"<<endl;
    s.reCtor(p6,sizeof(p6)/sizeof(p6[0]));
    s.showSeqList();
    c.showSeqList();
    mergeList(s,c);
    s.showSeqList();

//    <2>����������˳����ʾ����A��B��ʵ�֣�
//    C=AUB��C=AUB��C=A-B
//    A=AUB��A=AUB��A=A-B
    cout<<endl;
    cout<<" <2>����������˳����ʾ����A��B��ʵ�֣�C=AUB"<<endl;
    s.reCtor(p1,sizeof(p1)/sizeof(p1[0]));
    c.reCtor(p2,sizeof(p2)/sizeof(p2[0]));
    s.showSeqList();
    c.showSeqList();
    mergeSets(s,c,n);
    n.showSeqList();
    cout<<"<2>����������˳����ʾ����A��B��ʵ�֣�C=AnB"<<endl;
    s.showSeqList();
    c.showSeqList();
    n.clearSeqList();
    common(s,c,n);
    n.showSeqList();
    cout<<endl;
    //<3>����������˳����ʾ����A��B���ж�A�Ƿ�B���Ӽ�
    cout<<"<3>����������˳����ʾ����A��B���ж�A�Ƿ�B���Ӽ�"<<endl;
    cout<<"��һ�����ݣ�"<<endl;
    s.showSeqList();
    c.showSeqList();
    if(subset(&s,&c)) cout<<"��һ�������ǵڶ������Ӽ�"<<endl;
    else cout<<"��һ�����ϲ��ǵڶ������Ӽ�"<<endl;
    cout<<"�ڶ������ݣ�"<<endl;
    s.reCtor(p5,sizeof(p5)/sizeof(p5[0]));
    s.showSeqList();
    c.showSeqList();
    n.clearSeqList();
    if(subset(&s,&c)) cout<<"��һ�������ǵڶ������Ӽ�"<<endl;
    else cout<<"��һ�����ϲ��ǵڶ������Ӽ�"<<endl;


//    <4>(2011)��15 �֣�һ������ΪL��L��1������������S�����ڵ�L/2������ȡ������λ�õ�����ΪS ����λ����
//    ���磬������S1=(11, 13, 15, 17, 19)����S1 ����λ����15���������е���λ���Ǻ���������Ԫ�ص��������е���λ����
//    ���磬��S2=(2, 4, 6, 8, 20)����S1 ��S2 ����λ����11��
//    ���������ȳ���������A ��B�������һ����ʱ��Ϳռ������涼�����ܸ�Ч���㷨���ҳ���������A ��B ����λ����Ҫ��
//    ��1�������㷨�Ļ������˼�롣
//    ��2���������˼�룬����C ��C++���������㷨���ؼ�֮������ע�͡�
//    ��3��˵����������㷨��ʱ�临�ӶȺͿռ临�Ӷȡ�
    cout<<endl;
    cout<<"������<4>:�������ȳ��������е���λ��"<<endl;
    s.reCtor(p1,sizeof(p1)/sizeof(p1[0]));
    c.reCtor(p2,sizeof(p2)/sizeof(p2[0]));
    s.showSeqList();
    c.showSeqList();

    x=M_Search(s.data, c.data, sizeof(p1)/sizeof(p1[0]));
    cout<<"��λ��Ϊ��"<<x<<endl;

    cout<<"done!"<<endl;
    return 0;
}

//���ⷽ��



//�ȳ����������е���λ��
int M_Search(int A[], int B[], int n)
{
	int start1 = 0, end1 = n - 1, m1, start2 = 0, end2 = n - 1, m2;
	//�ֱ��ʾ����A��B����λ����ĩλ������λ��
	while (start1 != end1 || start2 != end2)
	{
		m1 = (start1 + end1) / 2;
		m2 = (start2 + end2) / 2;
		if (A[m1] == B[m2])
			return A[m1];   //�������� 1)
		if (A[m1]<B[m2]) // �������� 2)
		{
			if ((start1 + end1) % 2 == 0)  //��Ԫ�ظ���Ϊ����
			{
				start1 = m1;  //����A�м����ǰ�Ĳ����ұ����м��
				end2 = m2;  //����B�м���Ժ�Ĳ����ұ����м��
			}
			else				//Ԫ�ظ���Ϊż��
			{
				start1 = m1 + 1;  //����A�м�㼰�м����ǰ����
				end2 = m2;  //����B�м���Ժ󲿷��ұ����м��
			}
		}
		else
		{  //��������3)
			if ((start2 + end2) % 2 == 0)   //��Ԫ�ظ���Ϊ����
			{
				end1 = m1;    //����A�м���Ժ�Ĳ����ұ����м��
				start2 = m2;    //����B�м����ǰ�Ĳ����ұ����м��
			}
			else     //Ԫ�ظ���Ϊż��
			{
				end1 = m1;    //����A�м���Ժ󲿷��ұ����м��
				start2 = m2 + 1;    //����B�м�㼰�м����ǰ����
			}
		}
	}
	return  A[start1]<B[start2] ? A[start1] : B[start2];
}



//�ϲ�˳���
void ListMerge(SeqList A,SeqList B,SeqList * pC)
{
    int i;
    Type x;
    for(i=0;i<A.length();i++) {
        A.getElement(i+1,x);
        pC->listInsert(pC->length()+1,x);
    }
    for(i=0;i<B.length();i++) {
        B.getElement(i+1,x);
        if(!A.locate(x))
            pC->listInsert(pC->length(),x);
    }
}
//������������һ��Ԫ��
void insert(SeqList *L,Type x)
{
    int i=L->listLen-1;
    if(i>=MAXLEN-1) return;
    else {
        while(i>=0 && L->data[i]>x)
        {
            L->data[i+1]=L->data[i];
            i--;
        }
        L->data[i+1]=x;
        L->listLen++;
    }
}

//��ż��ֿ�
void seperate(SeqList& a,SeqList& b,SeqList& c)
{
    for(int i=1;i<=a.length();i++)
    {
        int s;
        a.getElement(i,s);
        if(s%2==0) b.listInsert(b.length()+1,s);
        else c.listInsert(c.length()+1,s);
    }
}

//���������������˳���Ĺ���Ԫ��
void common(SeqList& a,SeqList& b,SeqList& c)
{
    int ia=0,ib=0,ic=0;
    while(ia<a.length()&&ib<b.length())
    {
        if(a.data[ia]==b.data[ib]){
            //c.listInsert(c.length(),a.data[ia]);
            c.data[ic++]=a.data[ia];c.listLen++;
            ia++;ib++;
        }
        else if(a.data[ia]>b.data[ib]) ib++;
        else ia++;
    }
}

//ɾ����������˳����е��ظ�Ԫ��
int removeDuplicateEle(SeqList& a)
{
    int k=0;
    for(int i=1;i<a.length();i++){
        if(a.data[i]!=a.data[i-1]){
            a.data[++k]=a.data[i];
        }
    }

    return a.listLen=++k;
}

//��������ϲ���һ������A=AUB
void mergeList(SeqList& a,SeqList& b)
{
    removeDuplicateEle(a);
    removeDuplicateEle(b);
    int* c=new int[max(a.length(),b.length())];
    int t1=0,t2=0,k=0;
    while(t1<a.length()&&t2<b.length())
    {
        if(a.data[t1]==b.data[t2]){
            c[k++]=a.data[t1];
            t1++;t2++;
        }
        else if(a.data[t1]>b.data[t2]){
            c[k++]=b.data[t2];
            t2++;
        }
        else {
            c[k++]=a.data[t1];
            t1++;
        }
    }
    while(t2<b.length())
        c[k++]=b.data[t2++];

    while(t1<a.length())
        c[k++]=a.data[t1++];
    delete [] a.data;
    a.data=c;
    a.listLen=k;

}
//C=AUB
void mergeSets(SeqList& a,SeqList& b,SeqList& c1)
{

    int c[max(a.length(),b.length())];
//    c.clearSeqList();
//    c.data=new int[max(a.length(),b.length())];
    int t1=0,t2=0,k=0;
    while(t1<a.length()&&t2<b.length())
    {
        if(a.data[t1]==b.data[t2]){
            c[k++]=a.data[t1];
            t1++;t2++;
        }
        else if(a.data[t1]>b.data[t2]){
            c[k++]=b.data[t2];
            t2++;
        }
        else {
            c[k++]=a.data[t1];
            t1++;
        }
    }
    while(t2<b.length())
        c[k++]=b.data[t2++];

    while(t1<a.length())
        c[k++]=a.data[t1++];
    c1.reCtor(c,k);
}

//�ж�A�ǲ���B���Ӽ�����������ļ���
bool subset(SeqList *A,SeqList *B)
{
    int ia=0,ib=0;
    while(ia<A->length()&&ib<B->length())
    {
        if(A->data[ia]==B->data[ib]) {ia++;ib++;}
        else if(A->data[ia]>B->data[ib]) ib++;
        else return false;
    }
    if(ia>=A->length()) return true;
    else return false;

}
