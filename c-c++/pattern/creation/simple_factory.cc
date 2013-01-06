// product
class Shape {
  public:
    virtual void Draw() = 0;
};

class Circle : public Shape {
  public:
    void Draw() { cout << "I am circle" << endl; }
};

class Rectangle : public Shape {
  public:
    void Draw() { cout << "I am rectangle" << endl; }
};

// factory
class ShapeFactory {
  public:
    static Shape *Create(const string &type);
};

Shape *ShapeFactory::Create(const string &type) {
  if ("circle" == type)
    return new Circle();
  if ("rectangle" == type)
    return new Rectangle();
  return NULL;
}

// client
int main(void) {
  Shape *c = ShapeFactory::Create("circle");
  Shape *r = ShapeFactory::Create("rectangle");
  c->Draw();
  r->Draw();
}

// 简单工厂模式的最大优点在于工厂类中包含了必要的逻辑判断，根据客户端的选择条件动态实力化相关的类，对于客户端来说，去除了与具体产品的依赖。
// But violate open-closed principle
// So need factory method pattern
//
