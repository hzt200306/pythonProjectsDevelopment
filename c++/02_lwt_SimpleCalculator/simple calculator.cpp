//#define _CRT_SECURE_NO_WARNINGS
//
//// 引入必要的头文件，不必深究哦~
//#include <iostream>
//using namespace std;
//
//// 主角登场，这里是我们的主函数
//int main()
//{
//    // 想象一下，我们的计算器就像是一把神奇的魔法计算棒，只需要轻轻一点，就能得到答案。
//    // 而你是一位小小的商店老板，你需要用魔法计算棒算出购物的总价。
//    // 而现在，跟着小猫老板一起学习怎么构造简易计算器吧，喵~
//
//    // 快速了解一下我们的魔法工具：
//    // 1. cout用于显示信息 （cout << xxxx;)
//    // 2. cin用于获取输入  (cin >> xxxx >> endl(换行);)
//
//    // 定义两个数字，这是我们的魔法数字
//    double num1, num2;
//
//    // 小猫老板输入第一个数字
//    cout << "喵喵！请告诉我第一个数字：";
//    cin >> num1;
//
//    // 请注意，如果我们要进行除法，第二个数字不能是0哦喵~
//    cout << "如果要进行除法运算，请确保第二个数字不是0哦喵~" << endl;
//
//    // 小猫老板输入第二个数字
//    cout << "喵喵！再告诉我第二个数字：";
//    cin >> num2;
//
//    // 让我们一起看看魔法计算棒的威力！
//    cout << "嘿嘿，计算结果就要揭晓啦！" << endl;
//
//    // 加法计算
//    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
//
//    // 减法计算
//    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
//
//    // 乘法计算
//    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
//
//    // 除法计算
//    cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
//
//    // 不同数据类型的比较与说明
//    int intNum = 5;
//    double doubleNum = 5.5;
//
//    // 整数和浮点数在除法运算上的区别
//    cout << "整数和浮点数在除法运算上的区别：" << endl;
//    cout << intNum << " / " << intNum << " = " << intNum / intNum << " (整数除法，结果是整数)" << endl;
//    cout << doubleNum << " / " << intNum << " = " << doubleNum / intNum << " (浮点数除以整数，结果是浮点数)" << endl;
//
//    // 修饰符的介绍
//    // 再来感受一下魔法的力量，我们的计算器里有一个魔法开关，把它打开，我们就可以变出一个不可改变的数字。
//
//    // 魔法常量，不能被改变的数字
//    const double PI = 3.14159;
//
//    // 输出常量的值
//    cout << "喵，这是一个魔法常数：" << PI << endl;
//
//    // 尝试修改常量的值，发现魔法力量阻止了我们
//    // MAGIC_NUMBER = 3.14; // 错误了喵，魔法常量不可修改呢
//
//    // 更多修饰符的介绍
//    cout << "在计算魔法的世界里，我们还有一些特殊的修饰符，比如：" << endl;
//
//    // const修饰符
//    const int MAGIC_NUMBER = 42;
//    cout << "使用const修饰符创建的魔法数字：" << MAGIC_NUMBER << endl;
//
//    // static修饰符
//    static int staticNumber = 0;
//    cout << "使用static修饰符创建的数字，可以在函数调用之间保持其值：" << staticNumber << endl;
//    staticNumber++;
//
//    // 返回0是一个好的习惯哦喵~
//    return 0;
//}