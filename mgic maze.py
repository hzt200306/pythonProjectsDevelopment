#这个Python函数主要是实现了一个简单的文本冒险游戏。
#首先打印了一个欢迎信息，然后通过input函数获取用户输入的角色和任务。
#接下来使用f-string打印出了用户的任务和选择的角色，
#最后提醒用户开始冒险之旅
#数主要是通过文本和用户输入的交互来实现游戏的进行。
print("欢迎来到魔法迷宫！你是一名勇敢的探险者。")
role = input("请选择你的角色（骑士、巫师、猎人）: ")
task=input("请问你要穿过这个魔法迷宫是为了干什么呢？")
print(f"原来你来到这里{task}啊，听起来也太棒了吧！！")
print(f"那么勇敢的{role}，现在开始你的冒险之旅！")

#定义变量magic_items_collected 表示收集的魔法道具数量，初始化为0。
magic_items=0

#这是一个while循环，循环条件是magic_items(收集的魔法药水)少于三瓶。
#在每次循环中，会先打印一段文字，然后要求用户输入left或者right，表示选择不同的道路。
#这段代码会一直执行直到magic_items(收集的魔法药水)达到了三瓶
#提示玩家选择方向 向左走还是向右走？
while magic_items<3:
    print("\n你来到一个岔路口，你要选择走向哪个方向？ 小提示：勇于尝试不同的道路哦~~")
    direction = input("左边（left）右边（right） ")

    # 如果选择的是向左走，会碰到巫师，获得魔法药水
    if direction == 'left':
        print("你遇到了一位善良的巫师，他给了你一瓶魔法药水。")
        magic_items += 1

    # 向右走会碰到龙,玩家会碰到龙，展开斗争
    elif direction == 'right':

        #这里声明了两个变量 表示玩家的健康值 和龙的健康值
        player_health = 50
        dragon_health = 50

        #当满足 玩家或龙 任意一方健康值不为0 就会进入循环的条件
        # 也就是双方都还没有被打败的时候，这个打斗过程会一直持续
        while player_health > 0 and dragon_health > 0:

            print("\n你遇到了一条恶龙！一场激烈的战斗就此展开！")

            # 通过玩家的选择来决定使用哪一种攻击方式
            #不同的攻击方式会对龙造成不同的伤害，减少他们的健康值，或者增加自己的健康值
            action = input("你要使用魔法攻击（magic）、普通攻击（attack）还是进行防御（defend）？: ")

            if action == 'magic':
                print("你使用了魔法攻击，造成20点伤害！")
                dragon_health -= 20
            elif action == 'attack':
                print("你发起了普通攻击，造成10点伤害。")
                dragon_health -= 10
            else :
                print("你选择进行防御，减少了龙的伤害。")
                player_health +=10


            # 龙的反击给玩家的健康值造成伤害
            print("龙发起了反击，造成10点伤害！")
            player_health -= 10

            # 显示双方的健康值
            print(f"\n你的健康值: {player_health}")
            print(f"龙的健康值: {dragon_health}")

        #这是一个if else条件语句，检查玩家的健康值是否大于0。如果是，则打印
        #"你成功战胜了龙！"，否则打印"很遗憾，你被龙击败了。"。
        if player_health > 0:
            print("你成功战胜了龙！")
        else:
            print("很遗憾，你被龙击败了。")

    # 如果已经找到了三个魔法药水，就会不满足循环条件而推出while循环
    if magic_items >=3:
        print("你已经找到了3瓶魔法药水!此时岔路口在魔法药水的作用下消失了！\n")

    else:
        print("继续探险，寻找更多的魔法物品。")


print("此时你的眼前出现了三个障碍物！需要你使用魔法药水将它们移开！")

#这里使用了for循环，range(3)表示需要循环三次 ，循环3次，
# 该代码的目的是移开三次障碍物
for time in range(3):
    words = input(f"快这句说出魔法咒语：'障碍物消失吧！'")

print("恭喜移开了所有障碍物！")
# 游戏结束
print("\n你成功找到了迷宫的出口，完成了冒险之旅。")




