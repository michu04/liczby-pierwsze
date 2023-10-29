#include <iostream>
#include <chrono>

using namespace std::chrono;
using namespace std;

bool check1(unsigned long long q){
if(q == 0 || q == 1)
  return 0;
else
  for(int i=2; i<q; i++){
    if(q%i == 0)
      return 0;}
return 1;}

bool check2(unsigned long long q){
  if(q == 0 || q == 1)
    return 0;
  else
    if(q == 2)
      return 1;
    else
      if(q%2 == 0)
        return 0;
      else
        for(int i=3; i<q; i+=2){
          if(q%i == 0)
            return 0;}
return 1;}

bool check3(unsigned long long q){
if(q == 0 || q == 1)
  return 0;
else
  for(int i=2; i*i<=q; i++){
    if(q%i == 0)
      return 0;}
return 1;}

int naiwny1(unsigned long long n){
  unsigned long long q = 0;
  for(unsigned long long i=2; i<=n; i++)
    if(check1(i) == 1)
      q++;
return q;}

int naiwny2(unsigned long long n){
  unsigned long long q = 0;
  for(unsigned long long i=2; i<=n; i++)
    if(check2(i) == 1)
      q++;
return q;}

int naiwny3(unsigned long long n){
  unsigned long long q = 0;
  for(unsigned long long i=2; i<=n; i++)
    if(check3(i) == 1)
      q++;
return q;}

int eratostenes(unsigned long long n){
  unsigned long long tab[n+1];
  unsigned long long i,j,q=0;
  for(i=2; i<=n; i++)
    tab[i] = 1;

  for(i=2; i<=n/2; i++)
    for(j=2; i*j<=n; j++)
      tab[i*j] = 0;

  for(i=2; i<=n; i++)
    if(tab[i] == 1)
      q++;
return q;}

void time1(unsigned long long n){
  auto start = high_resolution_clock::now();
  cout << naiwny1(n) << " ";
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << "\n";}

void time2(unsigned long long n){
  auto start = high_resolution_clock::now();
  cout << naiwny2(n) << " ";
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << "\n";}

void time3(unsigned long long n){
  auto start = high_resolution_clock::now();
  cout << naiwny3(n) << " ";
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << "\n";}

void time4(unsigned long long n){
  auto start = high_resolution_clock::now();
  cout << eratostenes(n) << " ";
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << duration.count() << "\n";}

int main(){
  unsigned long long n = 1000;
  time1(n);
  time2(n);
  time3(n);
  time4(n);
return 0;}
