#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
// const int maxn = 100 + 10;  // 可以用const声明的常数作为数组声明参数，推荐写法。
// int A[maxn];

// void swap2(int& a, int& b){  
    /** 参数名前加 & 表示该参数按照引用传递。则在函数内改变参数的值也会修改到函数的实参。
     * 引用变量是一个别名，也就是说，它是某个已存在变量的另一个名字。一旦把引用初始化为某个变量，
     * 就可以使用该引用名称或变量名称来指向变量。 **/
//     int t = a; a = b; b = t;

// }

//结构体 struct
// struct Point
// {
//     int x, y;
//     Point(int x=0, int y=0):x(x), y(y) {}
// };

// Point operator + (const Point& A, const Point& B) {
//     /*定义加法*/
//     return Point(A.x + B.x, A.y + B.y);
// }

// ostream& operator << (ostream &out, const Point& p) {
//     /*定义该结构体的流输出方式*/
//     out << "(" << p.x << "," << p.y << ")";
//     return out;
// }

//模板 template
template<typename T>
T sum(T* begin, T* end) {
    T ans = 0;
    for(T* p = begin; p != end; p++)
        ans = ans + *p;
    return ans;
}


int main()
{
    // long long a, b;
    // while(cin >> a >> b){
    //     cout << min(a, b) << "\n";
    // }

    // int a = 3, b = 5;
    // swap2(a, b);
    // cout << a << " " << b << "\n";

    // cpp string类型 和字符串流
    // string line;
    // while (getline(cin, line))
    // {
    //     int sum = 0, x;
    //     stringstream ss(line);
    //     while (ss >> x)
    //         sum += x;
        
    //     cout << sum << "\n";
        
    // }

    // Point a, b(1, 2);
    // a.x = 3;
    // cout << a+b << "\n";

    double a[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    cout << sum(a, a+4) << "\n";


    return 0;
}