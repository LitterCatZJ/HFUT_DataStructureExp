#include<iostream>
#include "Forest.h"
using namespace std;

int main()
{
    Forest fo1("./tree11.txt");
    Forest fo2("./F20.txt");

    //(1)�����򡢺��򡢲�α���ɭ�֡�
    cout<<"(1)�����򡢺��򡢲�α���ɭ�֡�"<<endl;
    cout<<"��һ������tree11��"<<endl;
    fo1.print(1);fo1.print(2);fo1.print(3);
    cout<<"�ڶ�������f20: "<<endl;
    fo2.print(1);fo2.print(2);fo2.print(3);
    //(2)��ɭ�ֵĸ߶ȡ�
    cout<<"(2)��ɭ�ֵĸ߶ȡ�"<<endl;
    cout<<"��һ������tree11��"<<endl;
    cout<<fo1.height()<<endl;
    cout<<"�ڶ�������f20: "<<endl;
    cout<<fo2.height()<<endl;
    //(3)��ɭ�ֽ��������
    cout<<"(3)��ɭ�ֽ��������"<<endl;
    cout<<"��һ������tree11��"<<endl;
    cout<<fo1.node_count()<<endl;
    cout<<"�ڶ�������f20: "<<endl;
    cout<<fo2.node_count()<<endl;
    //(4)��ɭ��Ҷ�ӽ������
    cout<<"(4)��ɭ��Ҷ�ӽ������"<<endl;
    cout<<"��һ������tree11��"<<endl;
    cout<<fo1.leaves()<<endl;
    cout<<"�ڶ�������f20: "<<endl;
    cout<<fo2.leaves()<<endl;
    //(5)��ɭ�ֵĶȡ�
    cout<<"(5)��ɭ�ֵĶȡ�"<<endl;
    cout<<"��һ������tree11��"<<endl;
    cout<<fo1.degrees()<<endl;
    cout<<"�ڶ�������f20: "<<endl;
    cout<<fo2.degrees()<<endl;
    //(6)����������ֵ�����κš�
    cout<<"(6)����������ֵ�����κš�"<<endl;
    cout<<"��һ������tree11��"<<endl;
    fo1.print(4);
    cout<<"�ڶ�������f20: "<<endl;
    fo2.print(4);
    //(7)���������ʾ������
    cout<<"(7)���������ʾ������"<<endl;
    cout<<"��һ������tree11��"<<endl;
    fo1.print(6);
    cout<<"�ڶ�������f20: "<<endl;
    fo2.print(6);
    cout<<endl;
    cout<<"���"<<endl;
    return 0;
}
