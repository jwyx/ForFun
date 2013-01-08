// Flyweight, 运用共享技术有效地支持大量细粒度地对象。
//
// FlyweightFactory: 一个享元工厂，用来创建并管理Flyweight对象。它主要是用来确保合理地共享Flyweight, 当用户请求一个Flyweight时，FlyweightFactory对象提供一个已创建的实例或创建一个(如果不存在的话)；GetFlyweight(in key : int) : Flyweight
// Flyweight: 所有具体享元类的超类或接口，通过这个接口，Flyweight可以接受并作用于外部状态; Operation(in extrinsic state : int)
// ConcreteFlyweight: 继承Flyweight超类或实现Flyweight接口，并为内部状态增加存储空间
// UnsharedConcreteFlyweight: 指那些不需要共享的Flyweight子类。因为Flyweight接口共享成为可能，但它并不强制共享。
//
// 内部状态: 享元对象内部并且不会随环境改变而改变的共享部分
// 外部状态: 随环境改变而改变的，不可共享的状态就是外部状态
//
// 享元模式可以避免大量非常相似类的开销。在程序设计中，有时需要生成大量细粒度的类实例来表示数据。如果能发现这些实例除了几个参数外基本都是相同的，将这些参数移到类外面，在方法调用时将它们传递进来，就可以通过共享大幅度地减少单个实例地数目。
//
// 如果一个应用程序使用了大量地对象，而大量的这些对象造成了很大的存储开销时就应该考虑使用；还有就是对象的大多数状态可以外部状态，如果删除对象的外部状态，那么可以用相对较少的共享对象取代很多组对象，此时可以考虑使用享元模式
//
