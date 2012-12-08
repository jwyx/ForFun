// .h
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
    Shape *GetShape(const string &type);
};

// .cc
Shape *ShapeFactory::GetShape(const string &type) {
  if ("circle" == type)
    return new Circle();
  if ("rectangle" == type)
    return new Rectangle();
  return NULL;
}

int main(void) {
  ShapeFactory *factory = new ShapeFactory();
  Shape *c = factory->GetShape("circle");
  Shape *r = factory->GetShape("rectangle");
}
