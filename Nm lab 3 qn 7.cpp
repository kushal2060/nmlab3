#include<iostream>
#include<cmath>
using namespace std;
#define f(x) pow(2.71828,-x*x)
float a,b,choice;
float fun(float x){
	
	float d=0.5*(b-a);
	float u=d*x+(0.5)*(b+a);
	return (pow(2.71828,-u*u) )*d;
	
}

void twopoint(){
	int w1=1,w2=1;
	float x1=-1/sqrt(3),x2=1/sqrt(3),integration;
	if(b!=1&&a!=-1){
		integration=w1*fun(x1)+w2*fun(x2);
		
	
	}
	else{
		integration=w1*f(x1)+w2*f(x2);
	}
	
	cout<<"Integrated value is: "<<integration;
}
void threepoint(){
	float w1=0.56,w2=0.89,w3=0.56;
	float x1=-sqrt(0.6),x2=0,x3=sqrt(0.6),integration;
	if(b!=1&&a!=-1){
		integration=w1*fun(x1)+w2*fun(x2)+w3*fun(x3);
	}
	else{
		integration=w1*f(x1)+w2*f(x2)+w3*f(x3);
	  	}
	
	cout<<"Integrated value is: "<<integration;
}

int main(){
	
	cout<<"Enter the interval: ";
	cin>>a>>b;
	cout<<"Is it 2 point or 3 point: ";
	cin>>choice;
	if(choice==2){
		twopoint();
	}
	else{
		threepoint();
	}
	return 0;
}