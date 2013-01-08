// credit: <<大话设计模式>>
// 商场收银软件
// Context 与 Simple Factory 结合使用

// 策略算法(Strategy): 它定义了算法家族，分别封装起来，让它们之间可以互相替换，此模式让算法的变化，不会影响到是用算法的客户。

// Context: 上下文，用一个ConcreteStrategy 来配置，维护一个对Strategy对象的引用。Client通过Context的接口调用相应Strategy.
// Strategy: 策略类，定义所有支持算法的公共接口
// ConcreteStrategy: 继承于Strategy,封装了具体的算法或行为
