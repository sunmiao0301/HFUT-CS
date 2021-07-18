#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;
stack<int> num;
stack<string> cha;

bool panduan(string a){
	if(a=="*"||a=="-"||a=="+"||a=="/"||a=="#"||a=="("||a==")"||a=="!"||a=="|"||a=="&")
	   return true;
	else
	   return false;
}

int zhuanhuan(string a){
	if(a=="("||a==")") 
        return 6;
    else if(a=="!")
        return 5;
    else if(a=="&")
        return 4;
    else if(a=="|")
        return 3;
    else if(a=="*"||a=="/")
        return 2;
    else if(a=="+"||a=="-")
        return 1;
    else
        return 0;
}

int stringtoi(string str){
	istringstream is(str);
	int v;
	is>>v;
	return v;
}

int get_num(int i,string a,int &n){
	int num1=0;
	int i1=i+1;
	string m=a.substr(i,n);
	while(!panduan(a.substr(i1,1))){
		m=a.substr(i,n+1);
		n++;
		i1++;
	}
	num1=stringtoi(m);
	return num1;
}

int calculate(string a){
	int result=0;
	cha.push("#");
    for(int i=1;i<a.length();){
        int n=1;
		string m=a.substr(i,n);
		if(!panduan(m))	 num.push(get_num(i,a,n));			
		else{
			//cout<<"m为："<<m<<endl;
			string now=cha.top();
			//cout<<"now为："<<now<<endl;
			if(now=="("){
				cha.push(m);
				i++;
				continue;
			}
			if(zhuanhuan(m)>zhuanhuan(now)&&m!=")")	cha.push(m); 
		    while(zhuanhuan(m)<=zhuanhuan(now)||m==")"){		    	    
		    	    if(now=="(") break;
			        int top1=num.top();
			        num.pop();
			        //cout<<m<<endl;
			        //cout<<top1<<endl;				    
				    int top2;
				    if(!num.empty()){
				    	top2=num.top();
					    num.pop();
					}				    					
					//cout<<top2<<endl;
					if(now=="*"||now=="+"||now=="-"||now=="/"||now=="!"||now=="&"||now=="|"){
					    if(now=="*") num.push(top1*top2);
					    if(now=="+") num.push(top1+top2);
					    if(now=="-") num.push(top2-top1);
					    if(now=="/"){
					    	if(top1==0) {
					    		cout<<"请重新输入！"<<endl;
					    		return -9999;
							}  
					    	else num.push(top2/top1);
						} 
					    if(now=="!"){
						    num.push(top2);
						    if(top1!=0)  num.push(0);
						    else num.push(1);
					    }
					    if(now=="&"){
						    if(top1!=0&&top2!=0) num.push(1);
						    else num.push(0);
					    }
					    if(now=="|"){
						    if(top1!=0||top2!=0) num.push(1);
						    else num.push(0);
					    }
					//cout<<"结果为："<<num.top()<<endl;
					    cha.pop();
					    now=cha.top();	
					}
					else  num.push(top1);					
					//cout<<"now为："<<now<<m<<endl;
					if((now=="("&&m==")")||(now=="#"&&m=="#")){
						cha.pop();
						break;
					} 
					if(m!=")"&&m!="#") {
						cha.push(m);
						break;
					} 							
			    }			
		}
		i+=n;		
	}
	result=num.top();
	return result;
}

bool normalize(string a){
	if(a.length()==0||a.length()==1||a.substr(0,1)!="#"||a.substr(a.length()-1,1)!="#"){
		cout<<" 请重新输入！"<<endl;
		return false;
	} 
	stack<string> kuohao;
	int khL[a.length()];int k1=0;     //左括号下标的标记
	int khR[a.length()];int k2=0;
	for(int i=0;i<a.length();i++){
		khL[i]=0;                 //赋初值 
		khR[i]=0;
	}		
	for(int i=1;i<a.length();i++){         
		string now=a.substr(i,1);
		if((now!="*"&&now!="-"&&now!="+"&&now!="/"&&now!="#"&&now!="("&&now!=")"&&now!="!"&&now!="|"&&now!="&")&&(now!="0"&&now!="1"&&now!="2"&&now!="3"&&now!="4"&&now!="5"&&now!="6"&&now!="7"&&now!="8"&&now!="9")){
			cout<<"请重新输入！"<<endl; 
			return false; 
		} 
		if(now=="("||now==")"){
			kuohao.push(now);
			if(now=="("){
				khL[k1]=i;
				k1++;				
			}
			else{
				khR[k2]=i;
				k2++;
			}
		}
		if(now=="+"||now=="-"||now=="*"||now=="/"||now=="&"||now=="|"){
			if(panduan(a.substr(i-1,1))||panduan(a.substr(i+1,1))){
				if(a.substr(i-1,1)!=")"&&a.substr(i+1,1)!="(" && a.substr(i+1,1)!="!"){
					cout<<"请重新输入！"<<endl;
					return false;
				}					
			}
			if(now=="/"&&a.substr(i+1,1)=="0") {
				cout<<"请重新输入！"<<endl;
				return false;
			}
		}
		if(now=="!"){
			if(!panduan(a.substr(i-1,1))||a.substr(i-1,1)=="("||a.substr(i-1,1)==")"){
				cout<<"请重新输入！"<<endl; 
				return false;
			} 		    
		}				 
	} 
//****************下面为括号的报错******************* 
	if(k1!=k2){
		cout<<"请重新输入！"<<endl; 
		return false;
	}
	else{
		if(k1!=1){
			for(int m=0;m<khR[0]-khL[k1-1]-1;){
		        string m1=a.substr(khL[k1-1]+1+m,1);
		        if(!panduan(m1)){
			        m++;
			    if(m==khR[0]-khL[k1-1]-1){
				    cout<<"请重新输入！"<<endl;
				    return false;
			    }		    	
		    }
		        else break;		
	        }	
		int a1=0;
		while(!kuohao.empty()){
		    if(kuohao.top()==")") a1++;
		    else a1--;
		    kuohao.pop();
		    if(a1<0){
		    	cout<<"请重新输入！"<<endl;
				return false; 
			} 
	    }
	    for(int i=0;i<k1;i++){	    		
		    if(khR[k1-1-i]-khL[i]==1) {
			    cout<<"请重新输入！"<<endl;
		    	return false;     
		}
        //若有内容，括号使用正确	 
		    if((khR[i+1]-khR[i]==1)&&(khL[i+1]-khL[i]==1)){
			    cout<<"请重新输入！"<<endl;
			    return false;
		    }			    
	    }	
	}
	    else{
		    for(int m=0;m<khR[0]-khL[0]-1;){
		        string m1=a.substr(khL[0]+1+m,1);
		        if(!panduan(m1)){
			        m++;
			        if(m==khR[0]-khL[0]-1){
			            cout<<"请重新输入！"<<endl;
		        	    return false;
		            }		    	
	            }
	            else break;		
	        }	
	        int a1=0;
		    while(!kuohao.empty()){
		        if(kuohao.top()==")") a1++;
		        else a1--;
		        kuohao.pop();
		        if(a1<0){
		        	cout<<"请重新输入！"<<endl;
				    return false; 
			    } 
	        }
	    for(int i=0;i<k1;i++){	    		
		    if(khR[k1-1-i]-khL[i]==1) {
			    cout<<"请重新输入！"<<endl;
		    	return false;     
		    }
		}
	}
}
return true;	
}
