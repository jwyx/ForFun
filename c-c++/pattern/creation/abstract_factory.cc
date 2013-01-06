// abstract product A
class Shape2D {
  public:
    virtual void Draw() = 0;
    virtual ~Shape2D(){};
};

// product A1
class Circle2D : public Shape2D {
  public:
    void Draw() { cout << "I am circle in 2D" << endl; }
};

// product A2
class Rectangle2D : public Shape2D {
  public:
    void Draw() { cout << "I am rectangle in 2D" << endl; }
};

// abstract product B
class Shape3D {
  public:
    virtual void Draw() = 0;
    virtual ~Shape3D(){};
};

// product B1
class Circle3D : public Shape3D {
  public:
    void Draw() { cout << "I am circle in 3D" << endl; }
};

// product B2
class Rectangle3D : public Shape3D {
  public:
    void Draw() { cout << "I am rectangle in 3D" << endl; }
};

// abstract factory
class ShapeFactory {
  public:
    virtual Shape2D *GetShape2D(void) = 0;
    virtual Shape3D *GetShape3D(void) = 0;
    virtual ~ShapeFactory(){};
};

// factory 1
class CircleFactory : public ShapeFactory {
};

Shape2D *CircleFactory::GetShape2D(void) {
  return new Circle2D();
}

Shape3D *CircleFactory::GetShape3D(void) {
  return new Circle3D();
}

// factory 2
class RectangleFactory : public ShapeFactory {
};

Shape2D *RectangleFactory::GetShape2D(void) {
  return new Rectangle2D();
}

Shape3D *RectangleFactory::GetShape3D(void) {
  return new Rectangle3D();
}

// client
int main(void) {
  ShapeFactory *cf = new CircleFactory;
  ShapeFactory *rf = new RectangleFactory;

  Shape2D *c2D = cf->GetShape2D();
  Shape3D *c3D = cf->GetShape3D();
  Shape2D *r2D = rf->GetShape2D();
  Shape2D *r3D = rf->GetShape3D();

  c2D->Draw();
  c3D->Draw();
  r2D->Draw();
  r3D->Draw();
}

// 抽象工厂模式(Abstract Factory), 提供一个创建一系列相关或互相依赖对象的接口，
// 而无序指定他们具体的类。
