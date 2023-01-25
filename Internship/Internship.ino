list1=[]
list2=[]

def operation():
    ch = int(input('\n1.New Acount creation\n2.Deposit\n3.Withdrow\n4.Display accno having highest balance\n5.Exit\nEnter your choice '))

    class Bank_Account:
        
        def create(self,ac):
            self.ac=ac
            if self.ac in list1:
                print('Account number already exists')
            else:
                list1.append(self.ac)
                list2.append(100)

        def deposit(self,ac,bal):
            self.ac = ac
            self.bal = bal
            
            m = list1.index(self.ac)
            n = list2[m]
            p = n+self.bal
            list2.remove(n)
            list2.insert(m,p)
            print('Successfully deposited')

        def withdraw(self,ac,bal):
            self.ac = ac
            self.bal = bal
            m = list1.index(self.ac)
            n = list2[m]
            p = n-self.bal
            if p>100:
                list2.remove(n)
                list2.insert(m,p)
                print('Successfully withdrawn')
            else:
                print('Insufficient balance')

        def high_acc(self):
            h = max(list2)
            l = list2.index(h)
            k = list1[l]
            print('The account no having maximum balance ',k)

    c = Bank_Account()
    if ch == 1:
        acc = int(input('Enter the accno '))
        c.create(acc)
        operation()
    elif ch == 2:
        acc = int(input('Enter the existing accno '))
        if acc in list1:
            b = float(input('Enter the amount to be deposited:'))
            c.deposit(acc,b)
        else:
            print('The account number does not exist')
        operation()
    elif ch == 3:
        acc = int(input('Enter the existing accno '))
        if acc in list1:
            b = float(input('Enter the amount to be withdrawn '))
            c.withdraw(acc,b)
        else:
            print('The account does not exists ')
        operation()
    elif ch == 4:
        c.high_acc()
        operation()
    elif ch==5:
         exit()
         
operation()
