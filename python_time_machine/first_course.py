'''
因为是开学第一课，所以以建立总体概念为基础
    说明Python主要有什么内容：注释、变量、函数等等，然后以通俗易懂且富有童真的话告诉他们
    todo:问服务队相关负责人这个Python课程是不是上完scratch再弄这个
'''

# 让我们来解释一下代码中的几个要素：

# 注释：就像这段文字，它们是程序中的小提示，帮助我们（和其他读这段代码的魔法师）理解代码是如何工作的。
# 在Python中，注释以井号(#)开头，计算机在读到这些行时会忽略它们，因为它们是给人看的。

# 变量：变量就像是魔法帽里的小口袋，我们可以在里面存放一些东西（比如数字、文字、甚至是时间）。
# 在这个程序中，“now”就是一个变量，我们在里面存放了当前的日期和时间。

# 函数：函数像是预先准备好的魔法配方，我们只需要告诉它我们需要什么（有时候甚至不需要告诉它），它就会为我们完成一项任务。
# 例如，datetime.datetime.now()就是一个函数，它告诉我们现在的日期和时间。
# print也是一个函数，它把信息显示在屏幕上。

# 这段代码虽然简单，但它展示了编程中一些非常重要的概念。通过学习这些魔法的基础知识，
# 你将能够创造出更加复杂和有趣的魔法！

# 导入datetime模块
# 想象有一个魔法图书馆，里面存放着所有关于时间的秘密。当我们说“import datetime”时，
# 就像是我们拿到了这个图书馆的钥匙，可以使用里面的魔法书了。

import datetime

# 获取当前日期和时间
# 这里我们使用datetime模块中的一个特殊魔法——datetime.now()。
# 它就像一个神奇的镜子，可以反射出此刻的日期和时间。

now = datetime.datetime.now()

# 打印日期和时间
# 我们用print函数来告诉计算机，把我们找到的时间宝藏显示出来。
# print是一个非常有用的魔法咒语，它可以让隐藏的信息出现在我们的屏幕上。

print("当前的日期和时间是：", now)
