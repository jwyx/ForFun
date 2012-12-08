// .h
class Shape {
  public:
    virtual void Draw() = 0;
    static Shape *Create(const string &type);
};

class Circle : public Shape {
  public:
    void Draw() { cout << "I am circle" << endl; }
};

class Rectangle : public Shape {
  public:
    void Draw() { cout << "I am rectangle" << endl; }
};

// .cc
Shape *Create(const string &type) {
  if ("circle" == type)
    return new Circle();
  if ("rectangle" == type)
    return new Rectangle();
  return NULL;
}

int main(void) {
  Shape *c = Shape::Create("circle");
  Shape *r = Shape::Create("rectangle");
  c->Draw();
  r->Draw();
}

