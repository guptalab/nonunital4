#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
using namespace std;
   
vector<char> multiply(int a, vector<char> R);
vector<char> summation(vector<char> r1, vector<char> r2);
char multiplyDual(char r1, char R);
int k0=3;
int k1=2;
int n=6;
int NV=k1*(n-k0-k1);    // total dimension of Z = r*c
int pV=pow(2,NV);  //pow(2,N)  - combinations
int NT=k0*k1;
int pT=pow(2,NT);
int NU=k0*(n-k0-k1);
int pU=pow(2,NU);
int NA=k0+k0+k1;          // Size of Alpha = k0+k0+k1
int pA=pow(2,NA);
int NALL= n;
int pALL = pow(4,NALL);
vector<vector<int>> V( pV , vector<int> (NV, 0));
vector<vector<int>> T( pT , vector<int> (NT, 0));
vector<vector<int>> U( pU , vector<int> (NU, 0));
vector<vector<int>> Alpha(pA, vector<int> (NA, 0));
vector<vector<char>> ALL(pALL, vector<char> (NALL, 0));

vector<char> multiply(int a, vector<char> R)
{
    int n=R.size();
    vector<char> result(n,'0');
    for(int i=0;i<n;i++)
    {
       if(a==0)
        {
            result[i]='0';
        }
        else
        {
            result[i]=R[i];
        }   
    }
    return result;
}

char multiplyDual(char r1, char R)
{
    char result;
         if(r1=='0' && R=='0')
        {
            result='0';
        }
        else if(r1=='0' && R=='a')
        {
            result='0';
        }
        else if(r1=='0' && R=='b')
        {
            result='0';
        }
        else if(r1=='0' && R=='c')
        {
            result='0';
        }
        else if(r1=='a' && R=='0')
        {
            result='0';
        }
        else if(r1=='a' && R=='a')
        {
            result='a';
        }
        else if(r1=='a' && R=='b')
        {
            result='a';
        }
        else if(r1=='a' && R=='c')
        {
            result='0';
        }
        else if(r1=='b' && R=='0')
        {
            result='0';
        }
        else if(r1=='b' && R=='a')
        {
            result='b';
        }
        else if(r1=='b' && R=='b')
        {
            result='b';
        }
        else if(r1=='b' && R=='c')
        {
            result='0';
        }
        else if(r1=='c' && R=='0')
        {
            result='0';
        }
        else if(r1=='c' && R=='a')
        {
            result='c';
        }
        else if(r1=='c' && R=='b')
        {
            result='c';
        }
        else if(r1=='c' && R=='c')
        {
            result='0';
        }
    return result;
}

vector<char> summation(vector<char> r1, vector<char> r2)
{
    int n=r1.size();
    vector<char> result(n,'0');
    for(int i=0;i<n;i++)
    {
        if(r1[i]=='0' && r2[i]=='0')
        {
            result[i]='0';
        }
        else if(r1[i]=='0' && r2[i]=='a')
        {
            result[i]='a';
        }
        else if(r1[i]=='0' && r2[i]=='b')
        {
            result[i]='b';
        }
        else if(r1[i]=='0' && r2[i]=='c')
        {
            result[i]='c';
        }
        else if(r1[i]=='a' && r2[i]=='0')
        {
            result[i]='a';
        }
        else if(r1[i]=='a' && r2[i]=='a')
        {
            result[i]='0';
        }
        else if(r1[i]=='a' && r2[i]=='b')
        {
            result[i]='c';
        }
        else if(r1[i]=='a' && r2[i]=='c')
        {
            result[i]='b';
        }
        else if(r1[i]=='b' && r2[i]=='0')
        {
            result[i]='b';
        }
        else if(r1[i]=='b' && r2[i]=='a')
        {
            result[i]='c';
        }
        else if(r1[i]=='b' && r2[i]=='b')
        {
            result[i]='0';
        }
        else if(r1[i]=='b' && r2[i]=='c')
        {
            result[i]='a';
        }
        else if(r1[i]=='c' && r2[i]=='0')
        {
            result[i]='c';
        }
        else if(r1[i]=='c' && r2[i]=='a')
        {
            result[i]='b';
        }
        else if(r1[i]=='c' && r2[i]=='b')
        {
            result[i]='a';
        }
        else if(r1[i]=='c' && r2[i]=='c')
        {
            result[i]='0';
        }
    }
    return result;
}

void generateV(int n, int value, int range)
{
    if(n==0)
        return;
    if(value==0)
    {
        int i=0;
        while(i<pV)
        {
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                V[i][NV-n]=value;
            }
            i+=range;
        }
    }
    if(value==1)
    {
        int i=range;
        while(i<pV)
        {   
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                V[i][NV-n]=value;
            }
            i+=range;
        }
    }
    
    range=range/2;
    generateV(n-1,value,range);
}

void generateT(int n, int value, int range)
{
    if(n==0)
        return;
    if(value==0)
    {
        int i=0;
        while(i<pT)
        {
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                T[i][NT-n]=value;
            }
            i+=range;
        }
    }
    if(value==1)
    {
        int i=range;
        while(i<pT)
        {   
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                T[i][NT-n]=value;
            }
            i+=range;
        }
    }
    
    range=range/2;
    generateT(n-1,value,range);
}

void generateU(int n, int value, int range)
{
    if(n==0)
        return;
    if(value==0)
    {
        int i=0;
        while(i<pU)
        {
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                U[i][NU-n]=value;
            }
            i+=range;
        }
    }
    if(value==1)
    {
        int i=range;
        while(i<pU)
        {   
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                U[i][NU-n]=value;
            }
            i+=range;
        }
    }
    
    range=range/2;
    generateU(n-1,value,range);
}
void generateAlpha(int n, int value, int range)
{
    if(n==0)
        return;
    if(value==0)
    {
        int i=0;
        while(i<pA)
        {
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                Alpha[i][NA-n]=value;
            }
            i+=range;
        }
    }
    if(value==1)
    {
        int i=range;
        while(i<pA)
        {   
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                Alpha[i][NA-n]=value;
            }
            i+=range;
        }
    }
    
    range=range/2;
    generateAlpha(n-1,value,range);
}

void generateALL(int n, int value, int range)
{
    if(n==0)
        return;
    if(value==0)
    {
        int i=0;
        while(i<pALL)
        {
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                ALL[i][NALL-n]='0';
            }
            i+=(3*range);
        }
    }
    if(value==1)
    {
        int i=range;
        while(i<pALL)
        {   
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                ALL[i][NALL-n]='a';
            }
            i+=(3*range);
        }
    }
    if(value==2)
    {
        int i=2*range;
        while(i<pALL)
        {   
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                ALL[i][NALL-n]='b';
            }
            i+=(3*range);
        }
    }
    if(value==3)
    {
        int i=3*range;
        while(i<pALL)
        {   
            int prev_i=i;
            for(;i<prev_i+range;i++)
            {
                ALL[i][NALL-n]='c';
            }
            i+=(3*range);
        }
    }
    
    range=range/4;
    generateALL(n-1,value,range);
}

class G{
    public:
    vector<vector<char>> element;
    vector<vector<char>> CodeWords;
    vector<vector<char>> dualCodeWords;
    vector<int> e;
    vector<vector<int>> p;
    int dmin;
    int dualcount = 0;
    string nice;
    G() : element(NA , vector<char> (n,'0')), CodeWords( pA, vector<char> (n, '0')), dualCodeWords(pALL, vector<char> (n,' ')), e(n+1,0), p(pA,vector<int> (4,0)) {} //element(NA,n)  CodeWords(pA,n)
};

int main()
{
    int i,j,k,r,c;
    
    cout<< "n="<< n <<" k0="<< k0 << " k1="<< k1<< endl;
    vector<G> Gcomb;
    string nc = to_string(n);
    string k0c = to_string(k0);
    string k1c = to_string(k1);
    string filename = nc + "_" + k0c + "_"+ k1c;
    ofstream myfile;
    myfile.open ("codes\\"+filename+".html");
    myfile << "<!DOCTYPE html><html><head>n="<<n<<", k0="<<k0<<", k1="<<k1<<"<br>"; //starting html
   
    int range=pow(2,NT-1);
    generateT(NT,0,range);    //range=2^(NX-1)
    generateT(NT,1,range);
    
    range=pow(2,NU-1);
    generateU(NU,0,range);   //range=2^(NY-1)
    generateU(NU,1,range);
    
    range=pow(2,NV-1);
    generateV(NV,0,range);    //range=2^(NZ-1)
    generateV(NV,1,range);

    range=pow(4,NALL-1);
    generateALL(NALL,0,range);   //range=4^(NALL-1)
    generateALL(NALL,1,range);
    generateALL(NALL,2,range);
    generateALL(NALL,3,range);
   
    for(i=0;i<pT;i++)
    {
        for(j=0;j<pU;j++)
        {
            for(k=0;k<pV;k++)
            {
                vector<int> tempT=T[i];
                vector<int> tempU=U[j];
                vector<int> tempV=V[k];
                
                G tempG;
                int countt=0;
                int countu=0;
                int countv=0;
                
                int countt2=0;
                int countu2=0;
                for(r=0;r<k0;r++)
                {
                    for(c=0;c<k0;c++)
                    {
                        if(c==r)
                        {
                            tempG.element[r][c]='a';
                        }
                    }
                    for(;c<k0+k1;c++)
                    {
                        if(tempT[countt]==0)
                        {
                            tempG.element[r][c]='0';
                        }
                        else
                        {
                            tempG.element[r][c]='a';
                        }
                         countt++;
                    }
                    for(;c<n;c++)
                    {
                        if(tempU[countu]==0)
                        {
                            tempG.element[r][c]='0';
                        }
                        else
                        {
                            tempG.element[r][c]='a';
                        }
                        countu++;
                    }
                }
                
                for(;r<k0+k0;r++)
                {
                    for(c=0;c<k0;c++)
                    {
                        if(c==(r-k0))
                        {
                            tempG.element[r][c]='b';
                        }
                    }
                    for(;c<k0+k1;c++)
                    {
                        if(tempT[countt2]==0)
                        {
                            tempG.element[r][c]='0';
                        }
                        else
                        {
                            tempG.element[r][c]='b';
                        }
                        countt2++;
                    }
                    for(;c<n;c++)
                    {
                        if(tempU[countu2]==0)
                        {
                            tempG.element[r][c]='0';
                        }
                        else
                        {
                            tempG.element[r][c]='b';
                        }
                        countu2++;
                    }
                }

                  for(;r<k0+k0+k1;r++)
                {
                    c=k0;
                    for(;c<k0+k1;c++)
                    {
                        if(c==(r-k0))
                        {
                            tempG.element[r][c]='c';
                        }
                    }
                    
                    for(;c<n;c++)
                    {
                        if(tempV[countv]==0)
                        {
                            tempG.element[r][c]='0';
                        }
                        else
                        {
                            tempG.element[r][c]='c';
                        }
                        countv++;
                    }
                }
                Gcomb.push_back(tempG);;
               
            }
        }
    }
    
  
    
    int size=Gcomb.size();    
    
    range=pow(2,NA-1);
    generateAlpha(NA,0,range);   //range=2^(NA-1)
    generateAlpha(NA,1,range);
    
    size=Gcomb.size(); 
    
    vector<char> result;
    vector<vector<char>> tempCodes;
    for(i=0;i<size;i++)
    {
        for(j=0;j<pA;j++)
        {
            vector<char> sum(n,'0');
            for(k=0;k<NA;k++)
            {
                result=multiply(Alpha[j][k],Gcomb[i].element[k]);
                sum=summation(sum,result);
            }
            Gcomb[i].CodeWords[j]=sum;
        }
    }

    vector<char> dual(n,'0');
    int count = 0;
    int flag = 0;
    for(i=0;i<size;i++)  //for dualcode
    {
          for(j=0;j<pALL;j++)
        {
          flag=0;
          dual = ALL[j];
          for(k=0;k<NA;k++){
               count = 0;
                for (int m=0;m<n;m++){
                    if(multiplyDual(ALL[j][m], Gcomb[i].element[k][m]) == '0')
                    {
                       count++;
                    }
                }
                if(count != n){
                    //Gcomb[i].dualCodeWords[j] = dual;
                    flag = 1;
                    break;
                }
          }
          if(flag == 0){
            Gcomb[i].dualCodeWords[j] = dual;
            Gcomb[i].dualcount += 1;
          }
        }  
    }

     for(k=0;k<size;k++) //for min distance
    {
        int min=n;
        for (int i = 0; i < pA; i++)
        {
            for (int j = i+1; j < pA; j++)
            {
                //int d = abs(hw(Gcomb[k].CodeWords[i]) - hw(Gcomb[k].CodeWords[j]));
                int count =0;
                for (int m=0;m<n;m++){
                    if(Gcomb[k].CodeWords[i][m] != Gcomb[k].CodeWords[j][m])
                    count++;
                }
                if(min>count)
                {
                    min=count;
                }
            }   
        }
        Gcomb[k].dmin=min;
    }

    for(k=0;k<size;k++)  //for weight enumerator
    {
        for(int i=0; i<pA; i++)
        {
            int count = 0;
              for(int m=0;m<n;m++)
              {
                    if(Gcomb[k].CodeWords[i][m] != '0')
                    count++;
              }
              int weight = count;
               Gcomb[k].e[weight]+=1;
        }
    }
    //for complete weight enumerator
    for(k=0;k<size;k++)
    {
        for(int i=0;i<pA;i++)
        {
            int x0=0,xa=0,xb=0,xc=0;
           
              for(int m=0;m<n;m++)
              {
                    if(Gcomb[k].CodeWords[i][m] == '0'){
                        x0++;
                    }
                    else if(Gcomb[k].CodeWords[i][m] == 'a'){
                        xa++;
                    }
                    else if(Gcomb[k].CodeWords[i][m] == 'b'){
                        xb++;
                    }
                    else if(Gcomb[k].CodeWords[i][m] == 'c'){
                        xc++;
                    }
              }
              Gcomb[k].p[i][0] = x0;
              Gcomb[k].p[i][1] = xa;
              Gcomb[k].p[i][2] = xb;
              Gcomb[k].p[i][3] = xc;

        }
    }
    
    int maxDmin = 0;
    for(k=0;k<size;k++)  //for optimal minimum distance
    {
       if(Gcomb[k].dmin > maxDmin){
           maxDmin = Gcomb[k].dmin;
       }
    }
    cout<<"Optimal Minimum Distance: "<<maxDmin<<endl;
    myfile<<"Optimal Minimum Distance: "<<maxDmin<<"<br>";
    cout<<"Generator Matrices that generate Codes having Optimal Minimum Distance: ";
    myfile<<"Generator Matrices that generate Codes having Optimal Minimum Distance: ";

    int maxDminCount = 0;
    for(k=0;k<size;k++)
    {
       if(Gcomb[k].dmin == maxDmin){
           maxDminCount++;
           cout<<k+1<<", ";
           myfile<<k+1<<", ";
       }
    }
    cout<<endl;
    myfile<<"<br>";
    cout<<"Total No. of Codes having Optimal Minimum Distance: "<<maxDminCount<<endl; 
    myfile<<"Total No. of Codes having Optimal Minimum Distance: "<<maxDminCount<<"<br>";
    
    int c1=0,c2=0;
    int cond= pow(4,n);
    for(i=0;i<size;i++) //whether it's a nice code 
    { 
        c1=Gcomb[i].CodeWords.size();
        c2=Gcomb[i].dualcount;
        int mult = c1*c2;
        if(mult == cond) 
        {
            Gcomb[i].nice = "Yes";
        }
        else{
            Gcomb[i].nice = "No";
        }
    }

    cout<<"Generator Matrices that generate Nice Codes: ";
    myfile<<"Generator Matrices that generate Nice Codes : ";

    int niceFlag = 0;
    int niceCount = 0;
    for(k=0;k<size;k++)
    {
        if(Gcomb[k].nice == "Yes"){
            niceFlag = 1;
            niceCount++;
            cout<<k+1<<", ";
            myfile<<k+1<<", ";

        }
    }
    if(niceFlag == 0){
        cout<<"None";
        myfile<<"None";
    }

    cout<<endl;
    myfile<<"<br>";

    cout<<"Total No. of Nice Codes: "<<niceCount<<endl; 
    myfile<<"Total No. of Nice Codes: "<<niceCount<<"<br>";
    
    myfile<<"</head><body>";

    for(int i=0;i<size;i++)
    {
        //Gcomb[i].number = i+1;
        cout<<"\nG"<<i+1<<":\n";
        myfile<<"<h3>Generator Matrix-"<<i+1<<"</h3>";
        myfile<<"<p>";
        int size1=Gcomb[i].element.size();
        for(int j=0;j<size1;j++)
        {
            int size2=Gcomb[i].element[0].size();
            for(k=0;k<size2;k++)
            {
                cout<<Gcomb[i].element[j][k]<<" ";
                myfile<<Gcomb[i].element[j][k]<<" ";
            }
            myfile<<"<br>";
            cout<<endl;
        }
        myfile<<"</p>";
        cout<<endl<<"CodeWords:"<<endl;
        myfile<<"<h3>Codewords:</h3>";
        myfile<<"<p>";
        size1=Gcomb[i].CodeWords.size();
        for(j=0;j<size1;j++)
        {
            int size2=Gcomb[i].CodeWords[0].size();
            for(k=0;k<size2;k++)
            {
                cout<<Gcomb[i].CodeWords[j][k]<<" ";
                myfile<<Gcomb[i].CodeWords[j][k]<<" ";
            }
            cout<<endl;
            myfile<<"<br>";
        }
        myfile<<"</p>";
        cout<<"dmin: "<<Gcomb[i].dmin<<endl;
        myfile<<"<h4>dmin: "<<Gcomb[i].dmin<<"<br>";

        cout<<"Weight Enumerator: ";
        myfile<<"Weight Enumerator: ";
        for(int j=0;j<Gcomb[i].e.size();j++)
        {
            cout<<Gcomb[i].e[j]<<"x^"<<j;
            myfile<<Gcomb[i].e[j]<<"x<sup>"<<j<<"</sup>";

            if(j!=n){
               cout<<" + ";
               myfile<<" + ";
            } 
        }
        cout<<endl;
        myfile<<"<br>";

        cout<<"Complete Weight Enumerator: ";
        myfile<<"Complete Weight Enumerator: ";
        for(int j=0;j<Gcomb[i].p.size();j++){
            if(Gcomb[i].p[j][0]!=0){
            cout<<"(X_0)^"<<Gcomb[i].p[j][0];
            myfile<<"(X_0)<sup>"<<Gcomb[i].p[j][0]<<"</sup>";
            }
            if(Gcomb[i].p[j][1]!=0){
            cout<<" (X_a)^"<<Gcomb[i].p[j][1];
            myfile<<" (X_a)<sup>"<<Gcomb[i].p[j][1]<<"</sup>";
            }
            if(Gcomb[i].p[j][2]!=0){
            cout<<" (X_b)^"<<Gcomb[i].p[j][2];
            myfile<<" (X_b)<sup>"<<Gcomb[i].p[j][2]<<"</sup>";
            }
            if(Gcomb[i].p[j][3]!=0){
            cout<<" (X_c)^"<<Gcomb[i].p[j][3];
            myfile<<" (X_c)<sup>"<<Gcomb[i].p[j][3]<<"</sup>";
            }
            if(j!=Gcomb[i].p.size()-1){
                cout<<" + ";
                myfile<<" + ";
            }
        }
        cout<<endl;

        myfile<<"</h4>";
       cout<<endl<<"Dual CodeWords:"<<endl;
        myfile<<"<h3>Dual Codewords:</h3>";
        size1=Gcomb[i].dualCodeWords.size();
         for(j=0;j<size1;j++)
        {
            int size2=Gcomb[i].dualCodeWords[0].size();
            if(Gcomb[i].dualCodeWords[j][0] != ' '){
               for(k=0;k<size2;k++)
                { 
                    cout<<Gcomb[i].dualCodeWords[j][k]<<" ";
                    myfile<<Gcomb[i].dualCodeWords[j][k]<<" ";
                }
                cout<<endl;
                myfile<<"<br>";
            }
        }
        cout<<"Is it a nice code?: "<<Gcomb[i].nice<<endl;
        myfile<<"<h4>Is it a nice code?: "<<Gcomb[i].nice<<"</h4>";
      
    }
     //ending html
        myfile << "</body></html>";
        myfile.close();
        //system("codes\\" + filename + ".html");
    return 0;
        
}








