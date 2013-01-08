// credit: <<大话设计模式>>
// 做完的考卷设计

// 既然用了继承，并且肯定这个继承有意义，就应该要称为子类的模板，所有重复的代码都应该要上升到父类去，而不是让每个子类都去重复。
// 当我们要完成在某一个细节层次一致的一个过程或一系列步骤，但其个别步骤在更详细的层次上的实现可能不同，我们通常考虑模板方法模式来处理。
// 模板方法模式，定义一个操作中的算法骨架，而将一些步骤延迟到子类中。模板方法使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。
// AbstractClass: 抽象类，实现一个模板方法，定义算法的骨架，具体子类将重定义hook method以实现一个算法的步骤.这个模板方法一般是一个具体方法，它给出了一个顶级逻辑的骨架，而逻辑的组成步骤在相应的抽象操作中，推迟到子类实现。
// ConcreteClass: 实现hook method以完成算法中与特定子类相关的步骤。

// 模板方法模式特点：
//  通过把不变行为搬移到超类，去处子类中的重复代码来体现它的优势。
//  提供了一个很好的代码复用平台
//
// 当不变的和可变的行为在方法的子类中混合在一起的时候，不变的行为就会在子类中重复出现。通过模板方法模式把这些行为搬移到单一的地方，这样就帮助子类摆脱重复的不变行为的纠缠。
