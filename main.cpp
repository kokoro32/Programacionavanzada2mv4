#include <iostream>
#include <iomanip>
#include <fstream>
#include<string.h>
#include <vector>
#include"String_Tokenizer.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
using namespace std;
using std::string;
int main(int argc, char** argv) {
  ofstream myfile;
  std::ofstream ofs;
  int opc;
  myfile.open ("historial.txt",std::ofstream::out | std::ofstream::app);
  cout<<"Ingrese la operaci"<<char(162)<<"n que desea llevar a cabo"<<endl;
  cout<<"1.- Sumar"<<endl;
  cout<<"2.- Restar"<<endl;
  cout<<"3.- Multiplicar"<<endl;
  cout<<"4.- Dividr"<<endl;
  cin>>opc;
  do{
  string ecuacion, ecuacion2;
  //int r=0;
  float num,den, num2, den2;
    int num1,den1, num3, den3;
  int cont=0;
  int cont2=0;
  int cont3=0;
  int cont4=0;
  //string numb;
  string stringIntNum,stringIntDen,stringIntNum1,stringIntDen1;
  String_Tokenizer tokenizerForRac, tokenizerForRac1;
  cout<<"Por favor ingrese la primera ecuaci'\on"<<endl;
  cin>>ecuacion;
  fflush(stdin);
  cout<<"Por favor ingrese la segunda ecuaci'\on"<<endl;
  cin>>ecuacion2;
  fflush(stdin);
  String_Tokenizer tokenizer(ecuacion, ":");
  String_Tokenizer tokenizer2(ecuacion2, ":");
  vector<string> arr1;
  vector<string> arr2;
	//vector<string> arr2;
	while(tokenizer.has_more_tokens()){
        arr1.push_back(tokenizer.next_token());
        cont++;
    }//end while()
    	while(tokenizer2.has_more_tokens()){
        arr2.push_back(tokenizer2.next_token());
        cont2++;
    }//end while()
cont4=cont2-cont;
cont3=cont-cont2;
float nums[cont];
int nume[cont];
float dens[cont];
int deno[cont];
float numerito1[cont];
float nums2[cont2];
int nume2[cont2];
float dens2[cont2];
int deno2[cont2];
float numerito2[cont2];
for(int i=0;i<arr1.size();i++){
		tokenizerForRac=String_Tokenizer(arr1[i],"/");
		stringIntNum=tokenizerForRac.next_token();
		num=atof(stringIntNum.c_str());
		num1=atoi(stringIntNum.c_str());
		stringIntDen=tokenizerForRac.next_token();
		den=atof(stringIntDen.c_str());	
		den1=atoi(stringIntDen.c_str());
		nums[i]=num;
		nume[i]=num1;
		dens[i]=den;
		deno[i]=den1;
		numerito1[i]=(num/den);
	 						}
	for(int i=0;i<arr2.size();i++){
		tokenizerForRac1=String_Tokenizer(arr2[i],"/");
		stringIntNum1=tokenizerForRac1.next_token();
		num2=atof(stringIntNum1.c_str());
		num3=atoi(stringIntNum1.c_str());
		stringIntDen1=tokenizerForRac1.next_token();
		den2=atof(stringIntDen1.c_str());
		den3=atoi(stringIntDen1.c_str());
		nums2[i]=num2;
		nume2[i]=num3;
		dens2[i]=den2;
		deno2[i]=den3;	
		numerito2[i]=(num2/den2);
	}
	int y=0;
	if (cont2>=cont){
		y=cont;
	}
	else
	{
		y=cont2;
	}
	//FIJATE AQUI
	//TERMINA
	float resultado[y];
	int resultados[y];
	int resultados1[y];
  if(cont2>cont){
  for(int i=cont-1;i>=0;--i){
 	if(opc==1){
 		resultados1[i]=(deno[i]*deno2[i]);
 		resultados[i]=((nume[i]*deno2[i])+(nume2[i]*deno[i]));
 		resultado[i]=(numerito2[i]+numerito1[i]);
	 }
    else if(opc==2){
    	resultados1[i]=(deno[i]*deno2[i]);
 		resultados[i]=((nume[i]*deno2[i])-(nume2[i]*deno[i]));
    	resultado[i]=(numerito1[i]-numerito2[i]);
	}
    else if(opc==3){
    	resultados1[i]=(deno[i]*deno2[i]);
 		resultados[i]=(nume[i]*nume2[i]);
    	 resultado[i]=((nums2[i]*nums[i])/(dens2[i]*dens[i]));
	}
    else{
    	resultados1[i]=(deno[i]*nume2[i]);
 		resultados[i]=(nume[i]*deno2[i]);
    	resultado[i]=((nums[i]*dens2[i])/(nums2[i]*dens[i]));
	}
    
 }
  }else{
  for(int i=cont2-1;i>=0;--i){
 	if(opc==1){
 		resultados1[i]=(deno[i]*deno2[i]);
 		resultados[i]=((nume[i]*deno2[i])+(nume2[i]*deno[i]));
 		resultado[i]=(numerito2[i]+numerito1[i]);
	 }
    else if(opc==2){
    	resultados1[i]=(deno[i]*deno2[i]);
 		resultados[i]=((nume[i]*deno2[i])-(nume2[i]*deno[i]));
    	resultado[i]=(numerito1[i]-numerito2[i]);
	}
    else if(opc==3){
    	resultados1[i]=(deno[i]*deno2[i]);
 		resultados[i]=(nume[i]*nume2[i]);
    	 resultado[i]=((nums2[i]*nums[i])/(dens2[i]*dens[i]));
	}
    else{
    	resultados1[i]=(deno[i]*nume2[i]);
 		resultados[i]=(nume[i]*deno2[i]);
    	resultado[i]=((nums[i]*dens2[i])/(nums2[i]*dens[i]));
	}
    
 }	
}
myfile<<"Ecuacion 1: ";	
cout<<"Ecuacion 1: ";	
if(cont==1){
	myfile<<"("<<nume[0]<<"/"<<deno[0]<<")";
	cout<<"("<<nume[0]<<"/"<<deno[0]<<")";
}
else{
	myfile<<"("<<nume[0]<<"/"<<deno[0]<<")"<<" + ";
	cout<<"("<<nume[0]<<"/"<<deno[0]<<")"<<" + ";
}

for(int i=1;i<=cont-1;i++){
	if(i==cont-1){
		myfile<<"("<<nume[i]<<"/"<<deno[i]<<")X"<<char(94)<<i;
		cout<<"("<<nume[i]<<"/"<<deno[i]<<")X"<<char(94)<<i;
	}
	else{
		myfile<<"("<<nume[i]<<"/"<<deno[i]<<")X"<<char(94)<<i<<" + ";
		cout<<"("<<nume[i]<<"/"<<deno[i]<<")X"<<char(94)<<i<<" + ";
	}
}
myfile<<"\n";
cout<<"\n";
myfile<<"Ecuacion 2: ";	
cout<<"Ecuacion 2: ";	
if(cont2==1){
	myfile<<"("<<nume2[0]<<"/"<<deno2[0]<<")";
	cout<<"("<<nume2[0]<<"/"<<deno2[0]<<")";
}
else{
	myfile<<"("<<nume2[0]<<"/"<<deno2[0]<<")"<<" + ";
	cout<<"("<<nume2[0]<<"/"<<deno2[0]<<")"<<" + ";
}
for(int i=1;i<=cont2-1;i++){
	if(i==cont2-1){
		myfile<<"("<<nume2[i]<<"/"<<deno2[i]<<")X"<<char(94)<<i;
		cout<<"("<<nume2[i]<<"/"<<deno2[i]<<")X"<<char(94)<<i;
	}
	else{
		myfile<<"("<<nume2[i]<<"/"<<deno2[i]<<")X"<<char(94)<<i<<" + ";
		cout<<"("<<nume2[i]<<"/"<<deno2[i]<<")X"<<char(94)<<i<<" + ";
	}
}
myfile<<"\n";
cout<<"\n";
if(cont==1 && cont2==1){
	myfile<<"Resultado: ("<<resultados[0]<<"/"<<resultados1[0]<<")\n";
	cout<<"Resultado: ("<<resultados[0]<<"/"<<resultados1[0]<<")\n";
}
else{
	myfile<<"Resultado: ("<<resultados[0]<<"/"<<resultados1[0]<<") + ";
	cout<<"Resultado: ("<<resultados[0]<<"/"<<resultados1[0]<<") + ";
}
if(cont2>cont){
	for(int i=1;i<=cont-1;i++){
		if(cont==cont2){
			myfile<<"("<<resultados[i]<<"/"<<resultados1[i]<<")X^"<<i<<"\n";
			cout<<"("<<resultados[i]<<"/"<<resultados1[i]<<")X^"<<i<<"\n";
		}
		else{
			myfile<<"("<<resultados[i]<<"/"<<resultados1[i]<<")X^"<<i<<" + ";
			cout<<"("<<resultados[i]<<"/"<<resultados1[i]<<")X^"<<i<<" + ";
		}
}
for(int i=cont;i<=cont2-1;i++){
	if(i==cont2-1 || cont2-1==cont-1){
		myfile<<"("<<nume2[i]<<"/"<<deno2[i]<<")X^"<<i<<"\n";
		cout<<"("<<nume2[i]<<"/"<<deno2[i]<<")X^"<<i<<"\n";
	}
	else{
		myfile<<"("<<nume2[i]<<"/"<<deno2[i]<<")X^"<<i<<"+";
		cout<<"("<<nume2[i]<<"/"<<deno2[i]<<")X^"<<i<<"+";
	}
}
}else{
	for(int i=1;i<=cont2-1;i++){
	if(cont==cont2){
		myfile<<"("<<resultados[i]<<"/"<<resultados1[i]<<")X^"<<i<<"\n";
		cout<<"("<<resultados[i]<<"/"<<resultados1[i]<<")X^"<<i<<"\n";
	}
	else{
		myfile<<"("<<resultados[i]<<"/"<<resultados1[i]<<")X^"<<i<<" + ";
		cout<<"("<<resultados[i]<<"/"<<resultados1[i]<<")X^"<<i<<" + ";
	}
}
for(int i=cont2;i<=cont-1;i++){
	if(i==cont-1 || cont2-1==cont-1){
		myfile<<"("<<nume[i]<<"/"<<deno[i]<<")X^"<<i<<"\n";
		cout<<"("<<nume[i]<<"/"<<deno[i]<<")X^"<<i<<"\n";
	}
	else{
		myfile<<"("<<nume[i]<<"/"<<deno[i]<<")X^"<<i<<" + ";
		cout<<"("<<nume[i]<<"/"<<deno[i]<<")X^"<<i<<" + ";
	}
}
}
cout<<"Peque"<<char(164)<<"a pausa para que revise su resultado"<<endl;
Sleep(2000);
system ("cls");
  cout<<"Ingrese la operaci"<<char(162)<<"n que desea llevar a cabo"<<endl;
  cout<<"1.- Sumar"<<endl;
  cout<<"2.- Restar"<<endl;
  cout<<"3.- Multiplicar"<<endl;
  cout<<"4.- Dividr"<<endl;
  cout<<"5.- Salir"<<endl;
  cin>>opc; 	
  }while(opc!=5);
  myfile.close();  
	return 0;
}
