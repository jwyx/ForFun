// credit: <<大话设计模式>>
// 给人搭配不同服饰的系统
// 装饰链!

// 装饰模式(Decorator), 动态地给一个对象添加一些额外的职责，就增加功能来说，装饰模式比生成子类更为灵活.
//
// Component: 定义一个对象接口，可以给这些对象动态地添加职责。
// ConcreteComponent: 定义了一个具体的对象，也可以给这个对象添加一些职责.
// Decorator: 装饰抽象类，继承了Component类的功能，但对于Component来说，是无需知道Decoretor的存在。维护一个被装饰Component对象的引用。
// ConcreteDecorator: 具体的装饰对象，起到给Component添加职责的功能。
//
// 装饰模式是利用SetComponent来对对象进行包装的。这样每个装饰对象的实现就和如何使用这个对象分离开了，每个装饰对象只关心自己的功能，不需要关心如何被添加到对象链当中。
