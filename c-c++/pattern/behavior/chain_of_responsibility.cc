// 加薪申请
// Chain of Responsibility: 使多个对象都有机会处理请求，从而避免请求的发送者和接受者之间的耦合关系。将这个对象连成一条链，并沿着这条链传递该请求，直到有一个对象处理它为止。
//
// Handler: 定义一个处理请求的接口；SetSuccessor(in successor : Handler); HandleRequest(in request : int);
// ConcreteHandler: 具体处理者类，处理它所负责的请求，可访问它的后继者，如果可处理该请求，就处理之，否则就将该请求转发给它的后继者；HandleRequest(in request : int)
//

// 优点：
//  当客户提交一个请求时，请求是沿链传递直至有一个ConcreteHandler对象负责处理它。
//  请求者不管哪个对象来处理，反正该请求会被处理就对了。
//  当心一个请求有可能到了链的末端都得不到处理，或者因为没有配置正确而得不到处理
