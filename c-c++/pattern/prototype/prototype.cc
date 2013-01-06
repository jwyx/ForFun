// credit: <<大话设计模式>>
// credit: http://blog.csdn.net/outmanlee/article/details/7772007

// product
class Resume {
  private:
    char *m_name;

  public:
    char *GetName() { return m_name; }
    void SetName(const char *str);

    virtual ~Resume() { delete [] m_name; };
    virtual Resume *Clone() = 0; // key!!
    virtual Show() = 0;
};

void Resume::SetName(const char *str) {
  if (!str) {
    m_name = new char[1];
    m_name[0] = '\0';
  }
  else {
    m_name = new char[strlen(str) + 1];
    strcpy(m_name, str);
  }
}

// concrete product
class Resume1 : public Resume {
  public:
    Resume1(const char *str = NULL);
    Resume1(const Resume1 &r);
    Resume1 *Clone();
};

Resume1::Resume1(const char *str) {
  SetName(str);
}

Resume1::Resume1(const Resume1 &r) {
  SetName(r.GetName());
}

Resume1 *Resume1::Clone() {
  return new Resume1(*this);
}

void Resume1::Show() {
  cout << "Resume 1: " << GetName() << endl;
}

// client
int main() {
  Resume *r1 = new Resume1("1");
  r1->Show();
  Resume *r2 = r1->Clone();
  r2->Show();

  delete r1;
  r1 = NULL;

  // this should work!! It's deep copying.
  r2->Show();
  delete r2;
  r2 = NULL;
}


// 原型模式(prototype pattern) - 用原型实例指定创建对象的种类，
// 并且通过拷贝这些原型创建新的对象。
