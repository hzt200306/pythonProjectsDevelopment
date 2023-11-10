class Pet:
    def __init__(self, name, age, weight, is_online):
        self.name = name
        self.age = age
        self.weight = weight
        self.is_online = is_online
        self.friends = []

    def add_friend(self, friend_name, contact_info):
        friend = {
            "name": friend_name,
            "contact_info": contact_info
        }
        self.friends.append(friend)

    def age_to_string(self):
        return str(self.age)

# 创建虚拟小助手
name = input("请输入虚拟小助手的名字: ")
age = int(input("请输入年龄(数字)/岁: "))
weight = float(input("请输入体重(可以有小数)/kg: "))
is_online = input("是否在线 (True/False): ").lower() == "true"

pet = Pet(name, age, weight, is_online)

# 添加好友
num_friends = int(input("请输入好友数量: "))
for i in range(num_friends):
    print(f"第 {i+1} 个好友:")
    friend_name = input("好友名称: ")
    contact_info = input("好友联系方式: ")
    pet.add_friend(friend_name, contact_info)

# 显示虚拟小助手的信息
print("\n虚拟宠物或小助手信息:")
print(f"名字: {pet.name}")
print(f"年龄: {pet.age_to_string()} 岁")
print(f"体重: {pet.weight} 公斤")
print(f"是否在线: {pet.is_online}")

# 显示好友列表
print("\n好友列表:")
for friend in pet.friends:
    print(f"名字: {friend['name']}, 联系方式: {friend['contact_info']}")