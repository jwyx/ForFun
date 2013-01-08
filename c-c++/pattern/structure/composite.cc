// 整体和部分可以被一致对待
//
// 将对象组合成树形结构以表示‘部分－整体’的层次结构。组合模式使得用户对单个对象和组合对象的使用具有一致性。
// Component: 组合中道德对象声明接口，在适当情况下，实现所有类共有接口的默认行为。声明一个接口用于访问和管理Component的子部件。Add(in c: Component); Remove(in c: Component); Display(in depth: int);
// Leaf: 继承于Component, 在组合中表示叶节点对象，叶节点没有子节点; Display(in depth: int)
// Composite: 继承于Component, 定义有支节点行为，用来存储子部件，在Component接口中实现与子部件有关的操作，比如增加Add和删除Remove.
//
// Leaf实现无用的Add和Remove, 属于透明方式
// 仅将Add和Remove的声明放在Composit, 属于安全方法，但是调用者需要判断节点类型
