// product
class Shape {
  public:
    virtual void Draw() = 0;
    virtual ~Shape(){};
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
    virtual Shape *Create(void) = 0;
    virtual ~ShapeFactory(){};
};

class CircleFactory : public ShapeFactory {
};

class RectangleFactory : public ShapeFactory {
};

Shape *CircleFactory::Create(void) {
  return new Circle();
}

Shape *RectangleFactory::Create(void) {
  return new Rectangle();
}

// client
int main(void) {
  ShapeFactory *cf = new CircleFactory();
  ShapeFactory *rf = new RectangleFactory();
  Shape *c = cf->Create();
  Shape *r = rf->Create();
  c->Draw();
  r->Draw();
}

// Factory method pattern
// 定义一个用于创建对象的接口，让子类决定实例化哪一个类。工厂方法使一个类的实例化延迟到其子类。

