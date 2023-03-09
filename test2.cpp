#include <iostream> 
using namespace std; 

int fun1(int a, int b, int c, int d){ 
  return a+b; 
} 

int fun2(int a, int b, int c, int d){ 
  return a+b; 
} 

int fun21(int a, int b, int c){ 
  return a+b; 
} 

int fun22(int a, int b){ 
  return a+b; 
} 


int fun23(int a, int b, int c, int d, int e){ 
  return a+b; 
} 



int main() { 
    int n, t1 = 0, t2 = 1, nextTerm = 0; 
 
    cout << "Enter the number of terms: "; 
    cin >> n; 
 
    cout << "Fibonacci Series: "; 
 
    for (int i = 1; i <= n; ++i) { 
        if(i == 1) { 
            cout << t1 << ", "; 
            continue; 
        } 
        if(i == 2) { 
            cout << t2 << ", "; 
            continue; 
        } 
        nextTerm = t1 + t2; 
        t1 = t2; 
        t2 = nextTerm; 
         
        cout << nextTerm << ", "; 
    } 
 
    return 0; 
}

int main2() 
{ 
    int n, t1 = 0, t2 = 1, nextTerm = 0; 
 
    cout << "Enter the number of terms: "; 
    cin >> n; 
 
    cout << "Fibonacci Series: "; 
 
    for (int i = 1; i <= n; ++i) { 
        if(i == 1) { 
            cout << t1 << ", "; 
            continue; 
        } 
        if(i == 2) { 
            cout << t2 << ", "; 
            continue; 
        } 
        nextTerm = t1 + t2; 
        t1 = t2; 
        t2 = nextTerm; 
         
        cout << nextTerm << ", "; 
    } 
 
    return 0; 
}

int fun3() { 
    int n, t1 = 0, t2 = 1, nextTerm = 0; 
 
    cout << "Enter the number of terms: "; 
    cin >> n; 
 
    cout << "Fibonacci Series: "; 
 
    for (int i = 1; i <= n; ++i) { 
        if(i == 1) { 
            cout << t1 << ", "; 
            continue; 
        } 
        if(i == 2) { 
            cout << t2 << ", "; 
            continue; 
        } 
        nextTerm = t1 + t2; 
        t1 = t2; 
        t2 = nextTerm; 
         
        cout << nextTerm << ", "; 
    } 
 
    return 0; 
} 

int fun4() { 
    int n, t1 = 0, t2 = 1, nextTerm = 0; 
 
    cout << "Enter the number of terms: "; 
    cin >> n; 
 
    cout << "Fibonacci Series: "; 
 
    for (int i = 1; i <= n; ++i) { 
        if(i == 1) { 
            cout << t1 << ", "; 
            continue; 
        } 
        if(i == 2) { 
            cout << t2 << ", "; 
            continue; 
        } 
        nextTerm = t1 + t2; 
        t1 = t2; 
        t2 = nextTerm; 
         
        cout << nextTerm << ", "; 
    } 
 
    return 0; 
} 

int fun41() { 
    int n, t1 = 0, t2 = 1, nextTerm = 0; 
 
    for (int i = 1; i <= n; ++i) { 
        if(i == 1) { 
            cout << t1 << ", "; 
            continue; 
        } 
        if(i == 2) { 
            cout << t2 << ", "; 
            continue; 
        } 
        nextTerm = t1 + t2; 
        t2 = nextTerm; 
        
    } 
} 
int fun42() { 
    int n, t1 = 0, t2 = 1, nextTerm = 0; 
 
    for (int i = 1; i <= n; ++i) { 
        if(i == 1) { 
            cout << t1 << ", "; 
            continue; 
        } 
        if(i == 2) { 
            cout << t2 << ", "; 
            continue; 
        } 
        nextTerm = t1 + t2; 
        t1 = t2; 
        t2 = nextTerm; 
        
    } 
} 
