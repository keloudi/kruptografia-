#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

//Prime Checker
bool CheckIfPrime(int p1){
    if (p1==2){
            return true;
        }
    for(int i=2;i<p1;i++){
        if(p1%i==0){
            return false;
        }
    }
    return true;
}

//finds the starting prime
//for example, for the first chain that it will try, it will be p1=2. For the second, p1=3, etc
int FindP1(int tries, int PrimeArray[]){
    if(tries==1){
        return 2;
    }
    else{
        int p1=PrimeArray[0];
        bool flag=false;
        while(flag==false){
            flag=CheckIfPrime(p1);
            int i=0;
            if(flag==true){
                while(PrimeArray[i]!=0){
                    if(p1!=PrimeArray[i]){
                        return p1;
                        cout<<p1;
                        break;
                    }
                    i++;
                }
            }
            cout<<p1;
            p1++;
        }
    }
}

//tries to find the primes
int FindPrimes(int Chainlength, int PrimeArray[]){
    int tries=1;
    int p1;
    while(PrimeArray[Chainlength]==0){
        p1=FindP1(tries,PrimeArray);
        //,tries
        PrimeArray[0]=p1;
        cout<<p1;
        bool flag=true;
        int i=1;
        int PrimeValue=p1;
        while(flag==true && PrimeArray[Chainlength]==0){
            PrimeValue=pow(2,i-1);
            PrimeValue=PrimeValue*p1+(PrimeValue-1);
            flag=CheckIfPrime(PrimeValue);
            //cout<<PrimeValue;
            if (flag==true){
                PrimeArray[i]=PrimeValue;
                i++;
            }
            else break;
        }
        tries++;
    }
}





//Main begins now
main (){
    int ChainLength;
    printf("Chose how long do you want your chain to be");
    cin>>ChainLength;
//Handles errors in case the input is not an integer
    while(cin.fail()){
        printf("Enter an integer please");
        cin.clear();
        cin.ignore();
        cin>>ChainLength;
    }
    int PrimeArray[ChainLength];
    for (int i=0;i<=ChainLength;i++){
        PrimeArray[i]=0;
    }
    FindPrimes(ChainLength,PrimeArray);
    for(int i=1;i<=ChainLength;i++){
        printf("The chain's number in the position %u is %u \n",i,PrimeArray[i]);
    }

    }


