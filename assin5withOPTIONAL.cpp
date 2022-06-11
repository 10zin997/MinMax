//TENZIN WANGYAL(REDO)
//ASSIGNMENT 5 With OPTIONAL
//11/20/16
// This program will read a limit and a list of number from
//an input file.then it compares two numbers to give
//smallest,largest and equal value and print them.
//This program also has an optional to read in data after
//first list of data finishes.

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("inputOPTIONAL.txt");
ofstream fout("outputOPTIONAL.txt");

void readata(int [],int[],int &);
void printarray(int [],int);
int smallest(int [],int);
void construct(int [],int [],int [],int);
void whatshigher(int [],int [], int,int &,int &,int &);

int main()
{
      int score1[50],score2[50],sumscores[50],n,lowval;
      int tinynum1,tinynum2,smallestval,large,small,ditto;

      fin>>n;
      while(fin)
      {
            readata(score1,score2,n);
            fout<<"the score1 array: "<<endl;
            printarray(score1,n);
            fout<<"the score2 array: "<<endl;
            printarray(score2,n);
            fout<<endl;
            tinynum1=smallest(score1,n);
            fout<<"the smallest value in score1 is "<<tinynum1<<endl;
            tinynum2=smallest(score2,n);
            fout<<"the smallest value in score2 is "<<tinynum2<<endl<<endl;
            fout<<"the sumscores array: ";
            construct(score1,score2,sumscores,n);
            lowval=smallest(sumscores,n);
            fout<<"the smallest value in sumscores is "<<lowval<<endl<<endl;
            whatshigher(score1, score2,n,large, small, ditto);
            fout<<endl;
            fout<<"Array score1 was larger "<<large<<" times"<<endl;
            fout<<"Array score2 was larger "<<small<<" times"<<endl;
            fout<<"The two arrays were equal "<<ditto<<" times"<<endl<<endl;
            fin>>n;
      }
      fin.close();
      fin.close();
      return 0;
}


//void function readata receives 3 parameters.It reads the numbers from the file.
void readata(int nums1[], int nums2[],int &n)
{
      for(int i=0;i<n;i++)
      {
            fin>>nums1[i];
            fin>>nums2[i];
      }
      return;

}


//void function printarray receives 2 parameter.It lists the numbers from the file
void printarray(int vals[],int lim)
{
      for(int i=0;i<lim;i++)
            fout<<vals[i]<<" ";
      fout<<endl;
      return;
}


//int function smallest receives 2 parameter.It will compare two number in each
//array and send the smallest to main.
int smallest(int arr[],int num)
{
      int lowest=arr[0];

      for(int i = 1; i < num; i++)
      {
            if(arr[i]<lowest)
                  lowest = arr[i];
      }
      return lowest;
}


// void function construct receives 4 parameters.it will create a new array in main.
void construct(int first[],int second[],int summ[],int k)
{
      for(int i=0;i<k;i++)
      {
            summ[i]=first[i]+second[i];
      }
      printarray(summ,k);
      return;

}


//void function whatshigher receives 6 parameters.It will compare two numbers
// and send the larger or the equal one to main
void whatshigher(int score1[],int score2[], int n,int &greatest,int &lowest,int &same)
{
      greatest=0;lowest=0;same=0;
      for(int i=0;i<n;i++)
      {
            if(score1[i]>score2[i])
            {
                  fout<<"in postion "<<i<<", array score1 is larger: "
                      <<score1[i]<<" is larger than "<<score2[i]<<endl;
                  greatest++;
            }

            else if(score1[i]<score2[i])
            {
                        fout<<"in postion "<<i<<", array score2 is larger: "
                            <<score2[i]<<" is larger than "<<score1[i]<<endl;
                        lowest++;
            }

                  else
                  {
                        fout<<"in postion "<<i<<",the two array have the same value:"<<score1[i]<<endl;
                        same++;
                  }
      }
      return;
}
