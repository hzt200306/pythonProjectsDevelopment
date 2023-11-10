# 根据玩家选择采取不同的路径和使用控制流工具的代码

print("欢迎来到魔法迷宫！你是一名勇敢的探险者。")

# 角色选择
role = input("请选择你的角色（骑士、巫师、猎人）: ")

task=input("请问你要穿过这个魔法迷宫是为了干什么呢？")

print(f"原来你来到这里{task}啊，听起来也太棒了吧！！")

print(f"那么勇敢的{role}，现在开始你的冒险之旅！")

# 初始化游戏状态
magic_items_collected = 0
exit_found = False
player_inventory = []

while magic_items_collected!=3:
    print("\n你来到一个岔路口，你要选择走向哪个方向？ 小提示：勇于尝试不同的道路哦~~")
    direction = input("左边（left）右边（right） ")

    # 根据玩家选择展示不同的情节
    if direction.lower() == 'left':
        print("你遇到了一位善良的巫师，他给了你一瓶魔法药水和治疗药水。他告诉你要好好保管这两样东西。")
        magic_items_collected += 1


    elif direction.lower() == 'right':

        player_health = 50
        dragon_health = 50

        while player_health > 0 and dragon_health > 0:

            print("\n你遇到了一条恶龙！一场激烈的战斗就此展开！")
            action = input("你要使用魔法攻击（magic）、普通攻击（attack）、使用治疗药水（item）还是进行防御（defend）？: ")

            if action.lower() == 'magic':
                print("你使用了魔法攻击，造成20点伤害！")
                dragon_health -= 20
            elif action.lower() == 'attack':
                print("你发起了普通攻击，造成10点伤害。")
                dragon_health -= 10
            elif action.lower() == 'item':
                if '治疗药水' in player_inventory:
                    print("你使用了治疗药水，恢复了15点健康值。")
                    player_health += 15
                    player_inventory.remove('治疗药水')
                else:
                    print("你没有治疗药水，无法使用道具，由于耽误了时间，只能被攻击了。")
            elif action.lower() == 'defend':
                print("你选择进行防御，减少了龙的伤害。")
                player_health +=10  # 仅作示例，可以根据实际情况调整减少的伤害值
            else:
                print("无效的行动，请重新选择。")

            # 龙的反击
            print("龙发起了反击，造成15点伤害！")
            player_health -= 15

            # 显示战斗状态
            print(f"\n你的健康值: {player_health}")
            print(f"龙的健康值: {dragon_health}")

        # 判断战斗结果
        if player_health > 0:
            print("你成功战胜了龙！")
        else:
            print("很遗憾，你被龙击败了。")


    else:
        print("请问你要走到哪里去呀？重新选择一下吧~")

    # 使用控制流工具检查游戏进程
    if magic_items_collected >=3:
        print("你已经找到了3瓶魔法药水!此时岔路口在魔法药水的作用下消失了！\n")


    else:
        print("继续探险，寻找更多的魔法物品。")

print("此时你的眼前出现了障碍物！需要你使用魔法药水将它们移开！")
score = 0
obstacles = ["tree", "rock", "fire"]

while score < 3:
    obstacle = obstacles.pop(0)
    words=input(f"快说出魔法咒语:{obstacle}消失吧！")
    print("看！眼前的障碍物消失了!")
    score += 1

print("恭喜移开了所有障碍物！")

# 游戏结束
print("\n你成功找到了迷宫的出口，完成了冒险之旅。")




