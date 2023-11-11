class MagicCalculator:
    def __init__(self):
        self.result = 0

    def perform_magic(self,  operand1,operator, operand2=None):
        if operator == "加法魔法":
            self.result = operand1 + operand2
            print('加法魔法结果是：'+ str(self.result))
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
                        if operand2!= 0:
                            self.result = operand1 / operand2
                            print('除法结果是：' + str(self.result))
                            break
                    except ValueError:
                        print("小朋友，你输入的除数不能为0哦，请重新输入")
                        #如果小朋友输入正确，就重新进行运算
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
        for operation in operations:
            operand1, operator, operand2 = operation
            self.perform_magic(operand1, operator, operand2)

    def get_result(self):
        return self.result

def magic_calculator():
    while True:
        print("~~~~~~~~~~~~~~~欢迎来到魔法口袋计算器~~~~~~~~~~~~~~~")
        print("~~~~~~~~~~~~~~~输入数字1即可开始~~~~~~~~~~~~~~~~~~~")
        print("~~~~~~~~~~~~~~~输入非数字1的字符即可退出~~~~~~~~~~~~~")
        entry=input()
        if int(entry)== 1:
            print("~~~~~~~~~~~~~~~我们的运算模式有：~~~~~~~~~~~~~~~~\n1.数值运算魔法模式\n2.数值大小比较魔法模式")
            while True:
                    mode = input("请输入你要选择的运算模式(输入魔法模式的序号)：")
                    try:
                        mode=int(mode)
                        if int(mode)==1 or int(mode)==2:
                            mode = int(mode)
                            break
                        else:
                            print("小朋友，你输入的不是模式的序号哦，请重新输入")
                        # 如果小朋友输入正确，就重新进行运算
                            continue
                    except ValueError:
                        print("小朋友，你输入的不是模式的序号哦，请重新输入")
                        continue
            if mode == 1:
                print("~~~~~~~~~~~~~~~请输入你要进行的运算魔法口诀：~~~~~~~~~~~~~~~~\n1.加法魔法\n2.减法魔法\n3.乘法魔法\n4.除法魔法")
                while True:
                    try:
                        operand1 = int(input("请输入第一个数："))
                        break
                    except ValueError:
                        print("小朋友，你输入的不是数字哦，请重新输入")
                        continue
                while True:
                    while True:
                        operator = input("请输入你要进行的运算魔法口诀：")
                        if operator == "加法魔法" or operator == "减法魔法" or operator == "乘法魔法" or operator == "除法魔法":
                            break
                        else:
                            print("小朋友，你输入的运算魔法不正确哦，请重新输入")
                            continue
                    while True:
                        try:
                            operand2 = int(input("请输入下一个数："))
                            break
                        except ValueError:
                            print("小朋友，你输入的不是数字哦，请重新输入")
                            continue
                    calculator = MagicCalculator()
                    calculator.perform_magic(operand1, operator, operand2)
                # 询问是否进行下一轮计算
                    next_round = input("是否进行下一轮计算？(输入 '是' 继续，其他任意字符退出)：")
                    if next_round.lower() != '是':
                        print("经过魔法运算，结果是:"+str(calculator.get_result()))
                        break
                    else:
                        operand1 = calculator.get_result()
            elif mode == 2 :
                print("~~~~~~~~~~~~~~~我们的运算口诀有：~~~~~~~~~~~~~~~~\n1.等于魔法\n2.不等于魔法\n3.小于魔法\n4.大于魔法")
                calculator = MagicCalculator()
                while True:
                    try:
                        operand1 = input("请输入第一个数：")
                        operand1 = int(operand1)
                        break
                    except ValueError:
                        print("小朋友，你输入的不是数字哦，请重新输入")
                        continue
                while True:
                    operator = input("请输入你要进行的运算魔法口诀：")
                    if operator =="等于魔法" or operator == "不等于魔法" or operator == "大于魔法" or operator == "小于魔法":
                        break
                    else:
                        print("小朋友，你输入的运算魔法不正确哦，请重新输入")
                        continue
                # 判断输入的字符是不是数字
                while True:
                    try:
                        operand2 = input("请输入第二个数：")
                        operand2= int(operand2)
                        break
                    except ValueError:
                        print("小朋友，你输入的不是数字哦，请重新输入")
                        # 如果小朋友输入正确，就重新进行运算
                        continue
                calculator.perform_magic(operand1, operator, operand2)
        else:
            break

magic_calculator()
