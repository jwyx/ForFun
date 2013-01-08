// 建造者(builder): 将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
//
// Director: 是构建一个使用Builder接口的对象
// Builder: 是为创建一个Product对象的各个部件指定的抽象接口
// ConcreteBuilder: 继承于Builder, 实现Builder接口，构造和装配各个部件
// Product: 具体产品
//
// 何时需要：
//  主要是用于创建一些复杂的对象，这些对象内部构建间的建造顺序通常是稳定的
