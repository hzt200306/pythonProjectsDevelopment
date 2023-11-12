# 定义一个魔法计算器类
class MagicCalculator:
    def __init__(self):
        # 魔法计算器启动时，将结果设置为0
        self.result = 0

    def perform_magic(self, operand1, operator, operand2=None):
        """
        执行魔法运算

        参数：
        self：对象本身
        operand1：操作数1
        operator：运算符
        operand2：操作数2（可选）

        返回：
        None

        示例：
        perform_magic(10, "加法魔法")   # 10 + operand2 的结果是：加法魔法结果是：10
        perform_magic(10, "减法魔法", 5)   # 10 - 5 的结果是：减法魔法结果是：5
        perform_magic(6, "乘法魔法", 3)   # 6 * 3 的结果是：乘法魔法结果是：18
        perform_magic(15, "除法魔法", 5)   # 15 / 5 的结果是：除法结果是：3
        perform_magic(10, "等于魔法", 10)   # 10 等于 10
        perform_magic(10, "不等于魔法", 20)   # 10 不等于 20
        perform_magic(10, "大于魔法", 5)   # 10 大于 5
        perform_magic(10, "小于魔法", 20)   # 10 不小于 20
        """
        if operator == "加法魔法":
            self.result = operand1 + operand2
            print('加法魔法结果是：' + str(self.result))
        elif operator == "减法魔法":
            self.result = operand1 - operand2
            print('减法魔法结果是：' + str(self.result))
        elif operator == "乘法魔法":
            self.result = operand1 * operand2
            print('乘法魔法结果是：' + str(self.result))
        elif operator == "除法魔法":
            if operand2 != 0:
                self.result = operand1 / operand2
                print('除法结果是：' + str(self.result))
            else:
                print("错误！小朋友，除数不能为零哦")
                while True:
                    try:
                        operand2 = int(input("请输入除数："))
                        if operand2 != 0:
                            self.result = operand1 / operand2
                            print('除法结果是：' + str(self.result))
                            break
                    except ValueError:
                        print("小朋友，你输入的除数不能为0哦，请重新输入")
                        # 如果小朋友输入正确，就重新进行运算
                        continue
        elif operator == '等于魔法':
            self.result = operand1 == operand2
            if self.result:
                print(f"{operand1}等于{operand2}")
            else:
                print(f"{operand1}不等于{operand2}")
        elif operator == "不等于魔法":
            self.result = operand1 != operand2
            if self.result:
                print(f"{operand1}不等于{operand2}")
            else:
                print(f"{operand1}等于{operand2}")
        elif operator == "大于魔法":
            self.result = operand1 > operand2
            if self.result:
                print(f"{operand1}大于{operand2}")
            else:
                print(f"{operand1}不大于{operand2}")
        elif operator == "小于魔法":
            self.result = operand1 < operand2
            if self.result:
                print(f"{operand1}小于{operand2}")
            else:
                print(f"{operand1}不小于{operand2}")

    def perform_multiple_operations(self, operations):
        """
        # 假设你已经创建了一个MagicCalculator的实例
        calculator = MagicCalculator()

        # 定义一系列的运算
        # 这里每个元组包含两个操作数和一个运算符
        operations = [
            (5, "加法魔法", 3),  # 表示 5 + 3
            (8, "减法魔法", 2),  # 表示 8 - 2
            (10, "乘法魔法", 4), # 表示 10 * 4
            (20, "除法魔法", 5)  # 表示 20 / 5
        ]

        # 执行这些运算
        calculator.perform_multiple_operations(operations)

        # 每次运算的结果会被打印出来
        # 如果你想查看最后一次运算的结果，可以使用
        print("最后的运算结果是:", calculator.result)
        """
        for operation in operations:
            operand1, operator, operand2 = operation
            self.perform_magic(operand1, operator, operand2)

        def get_result(self):
            """
            获取结果

            Args:
                self: 对象本身

            Returns:
                result: 结果值

            """
            return self.result



def magic_calculator():
    while True:
        # 打印欢迎信息
        print("~~~~~~~~~~~~~~~欢迎来到魔法口袋计算器~~~~~~~~~~~~~~~")
        print("~~~~~~~~~~~~~~~输入数字1即可开始~~~~~~~~~~~~~~~~~~~")
        print("~~~~~~~~~~~~~~~输入非数字1的字符即可退出~~~~~~~~~~~~~")
        entry = input()
        if int(entry) == 1:
            # 选择魔法计算模式
            # 魔法模式1：数值运算魔法模式，可以进行加减乘除等操作
            # 魔法模式2：数值大小比较魔法模式，可以比较数字的大小
            # 打印运算模式选项
            print("~~~~~~~~~~~~~~~我们的运算模式有：~~~~~~~~~~~~~~~~\n1.数值运算魔法模式\n2.数值大小比较魔法模式")
            while True:
                # 获取选择的运算模式
                mode = input("请输入你要选择的运算模式(输入魔法模式的序号)：")
                try:
                    mode = int(mode)
                    if int(mode) == 1 or int(mode) == 2:
                        mode = int(mode)
                        break
                    else:
                        # 如果输入的不是模式的序号，提示重新输入
                        print("小朋友，你输入的不是模式的序号哦，请重新输入")
                        continue
                except ValueError:
                    # 如果输入的不是模式的序号，提示重新输入
                    print("小朋友，你输入的不是模式的序号哦，请重新输入")
                    continue
            if mode == 1:
                # 打印数值运算魔法口诀选项
                print(
                    "~~~~~~~~~~~~~~~请输入你要进行的运算魔法口诀：~~~~~~~~~~~~~~~~\n1.加法魔法\n2.减法魔法\n3.乘法魔法\n4.除法魔法")
                while True:
                    try:
                        # 获取第一个数
                        operand1 = int(input("请输入第一个数："))
                        break
                    except ValueError:
                        # 如果输入的不是数字，提示重新输入
                        print("小朋友，你输入的不是数字哦，请重新输入")
                        continue
                while True:
                    while True:
                        # 获取运算魔法口诀
                        operator = input("请输入你要进行的运算魔法口诀：（如输入“加法魔法”）")
                        if operator == "加法魔法" or operator == "减法魔法" or operator == "乘法魔法" or operator == "除法魔法":
                            break
                        else:
                            # 如果输入的运算魔法不正确，提示重新输入
                            print("小朋友，你输入的运算魔法不正确哦，请重新输入")
                            continue
                    while True:
                        try:
                            # 获取下一个数
                            operand2 = int(input("请输入下一个数："))
                            break
                        except ValueError:
                            # 如果输入的不是数字，提示重新输入
                            print("小朋友，你输入的不是数字哦，请重新输入")
                            continue
                    calculator = MagicCalculator()
                    # 进行魔法运算
                    calculator.perform_magic(operand1, operator, operand2)
                # 询问是否进行下一轮计算
                next_round = input("是否进行下一轮计算？(输入 '是' 继续，其他任意字符退出)：")
                if next_round.lower() != '是':
                    # 输出运算结果
                    print("经过魔法运算，结果是:" + str(calculator.get_result()))
                    break
                else:
                    # 进行下一轮计算，将结果作为新的第一个数
                    operand1 = calculator.get_result()
            elif mode == 2:
                # 打印数值大小比较魔法口诀选项
                print(
                    "~~~~~~~~~~~~~~~我们的运算口诀有：~~~~~~~~~~~~~~~~\n1.等于魔法\n2.不等于魔法\n3.小于魔法\n4.大于魔法")
                calculator = MagicCalculator()
                while True:
                    try:
                        # 获取第一个数
                        operand1 = input("请输入第一个数：")
                        operand1 = int(operand1)
                        break
                    except ValueError:
                        # 如果输入的不是数字，提示重新输入
                        print("小朋友，你输入的不是数字哦，请重新输入")
                        continue
                while True:
                    # 获取运算魔法口诀
                    operator = input("请输入你要进行的运算魔法口诀：（如输入“等于魔法”）")
                    if operator == "等于魔法" or operator == "不等于魔法" or operator == "大于魔法" or operator == "小于魔法":
                        break
                    else:
                        # 如果输入的运算魔法不正确，提示重新输入
                        print("小朋友，你输入的运算魔法不正确哦，请重新输入")
                        continue
                # 获取第二个数
                while True:
                    try:
                        operand2 = input("请输入第二个数：")
                        operand2 = int(operand2)
                        break
                    except ValueError:
                        # 如果输入的不是数字，提示重新输入
                        print("小朋友，你输入的不是数字哦，请重新输入")
                        continue
                # 进行魔法运算
                calculator.perform_magic(operand1, operator, operand2)
        else:
            # 非法输入，退出程序
            break


magic_calculator()
