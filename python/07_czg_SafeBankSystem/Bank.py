class TransactionLimitExceeded(Exception): # 自定义异常类，当交易金额超过限额时触发
    def __init__(self, limit):
        self.limit = limit # 设定交易限额
        super().__init__(f"交易金额超过限额 {limit} 元") # 调用父类的初始化方法，设置异常信息

class Bank:
    def __init__(self, name, limit): # 初始化银行，设定银行名称和交易限额
        self.name = name # 设定银行名称
        self.limit = limit # 设定交易限额
        self.accounts = {} # 创建一个空的账户字典

    def create_account(self, account_number, name): # 创建账户，如果账户已存在则抛出异常
        try:
            if account_number in self.accounts: # 检查账户是否已存在
                raise Exception("无效的账户号码") # 如果账户已存在，抛出异常
            self.accounts[account_number] = {"name": name, "balance": 0} # 如果账户不存在，创建新账户
            print(f"{name} 账户 {account_number} 创建成功。") # 打印账户创建成功的信息
        except Exception as e:
            print(f"创建账户失败，原因：{e}") # 打印异常信息

    def deposit(self, account_number, amount): # 存款，如果账户不存在或存款金额为负则抛出异常
        try:
            if account_number not in self.accounts: # 检查账户是否存在
                raise Exception("无效的账户号码") # 如果账户不存在，抛出异常
            if amount < 0: # 检查存款金额是否为负
                raise Exception("存款金额不能为负数") # 如果存款金额为负，抛出异常
            if amount > self.limit: # 检查存款金额是否超过限额
                raise TransactionLimitExceeded(self.limit) # 如果存款金额超过限额，抛出自定义异常
            self.accounts[account_number]["balance"] += amount # 如果账户存在且存款金额不为负且不超过限额，进行存款操作
            balance = self.accounts[account_number]["balance"] # 获取存款后的账户余额
            print(f"您已成功存入 {amount} 元。您的账户余额为 {balance} 元。") # 打印存款成功和当前余额的信息
        except Exception as e:
            print(f"存款失败，原因：{e}") # 打印异常信息

    def withdraw(self, account_number, amount): # 取款，如果账户不存在或取款金额超出余额则抛出异常
        try:
            if account_number not in self.accounts: # 检查账户是否存在
                raise Exception("无效的账户号码") # 如果账户不存在，抛出异常
            if amount < 0: # 检查取款金额是否为负
                raise Exception("取款金额不能为负数") # 如果取款金额为负，抛出异常
            if amount > self.accounts[account_number]["balance"]: # 检查取款金额是否超过账户余额
                raise Exception("余额不足") # 如果取款金额超过账户余额，抛出异常
            if amount > self.limit: # 检查取款金额是否超过限额
                raise TransactionLimitExceeded(self.limit) # 如果取款金额超过限额，抛出自定义异常
            self.accounts[account_number]["balance"] -= amount # 如果账户存在且取款金额不为负且不超过账户余额且不超过限额，进行取款操作
            balance = self.accounts[account_number]["balance"] # 获取取款后的账户余额
            print(f"您已成功取出 {amount} 元。您的账户余额为 {balance} 元。") # 打印取款成功和当前余额的信息
        except Exception as e:
            print(f"取款失败，原因：{e}") # 打印异常信息

    def get_balance(self, account_number): # 查询账户余额，如果账户不存在则抛出异常，并返回余额
        try:
            if account_number not in self.accounts: # 检查账户是否存在
                raise Exception("无效的账户号码") # 如果账户不存在，抛出异常
            balance = self.accounts[account_number]["balance"] # 获取账户余额
            print(f"您的账户余额为 {balance} 元。") # 打印账户余额的信息
            return balance # 返回账户余额
        except Exception as e:
            print(f"查询余额失败，原因：{e}") # 打印异常信息

    def change_name(self, account_number, new_name): # 更改账户姓名，如果账户不存在则抛出异常，并更新姓名信息
        try:
            if account_number not in self.accounts: # 检查账户是否存在
                raise Exception("无效的账户号码") # 如果账户不存在，抛出异常
            old_name = self.accounts[account_number]["name"] # 获取旧的账户姓名
            self.accounts[account_number]["name"] = new_name # 更新账户姓名
            print(f"{account_number} 的账户姓名已从 {old_name} 变更为 {new_name}。") # 打印账户姓名变更的信息
        except Exception as e:
            print(f"更改姓名失败，原因：{e}") # 打印异常信息

bank = Bank('ABC银行', 5000) # 创建一个名为'ABC银行'的银行实例，设定交易限额为5000元
bank.create_account(123, '张三') # 在'ABC银行'中创建一个账户号码为123，姓名为'张三'的账户
bank.deposit(123, 1000) # 向账户号码为123的账户存入1000元
bank.withdraw(123, 500) # 从账户号码为123的账户取出500元
