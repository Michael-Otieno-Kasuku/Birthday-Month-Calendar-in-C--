#include<iostream>
#include<stdlib.h>
#include<stdbool.h>
using namespace std;

class BirthDay{
	private:
		string names[12]={"January","February","March","April","May","June","July","August","September","Octotober","November","December"};
		int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		int day;
		int month;
		int year;
    public:
    	bool checkyear(){
    		if(year%4==0){
    			days[1]=29;
    			return true;
			}
			else{
				days[1]=28;
				return false;
			}
		}
		void setMonth(){
			cout<<"Enter the month: ";
			cin>>month;
		}
		void setYear(){
			cout<<"Enter the year: ";
			cin>>year;
		}
		int getMonth(){
			return month;
		}
		int getYear(){
			return year;
		}
		int firstJan(){
			return(5*((year-1)%4)+4*((year-1)%100)+6*((year-1)%400))%7;
		}
		void birthDay(){
		system("CLS");
		int sum = firstJan();
	    for(int i=month-2;i>=0;i--){sum+=days[i];}
	    day = sum%7;
        cout<<"Calendar for "<<names[month-1]<<" "<<year<<"\n";
	    cout<<"Mo\tTu\tWe\tTh\tFr\tSa\tSu\n";
	    if(month==1){
	    	days[month-2]=31;
		}
	    for(int j=days[month-2]-day+1;j<=days[month-2];j++){
           cout<<j<<"\t";
		}
        for(int k=1;k<=days[month-1];k++){
		if((day+1+k)%7==1){
			cout<<k<<"\t"<<"\n";
		}
		else{
			cout<<k<<"\t";
		}
	}
	day = (day + days[month-1])%7;
	 for(int k=1;k<=days[month];k++){
	 	if((day+1+k)%7==1){
			cout<<k;break;
		}
		else{
			cout<<k<<"\t";
		}
}
}
};
int main(){
	BirthDay m;
	m.setYear();
	m.setMonth();
	m.checkyear();
	m.birthDay();
	return 0;
}
