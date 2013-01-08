// singleton: 保证一个类仅有一个实例，并提供一个访问它的全局访问点
class Logger {
  public:
    static Logger *Instance();
  private:
    Logger(const Logger&) {} // copy constructor
    Logger &operator=(const Logger&) {} // assignment operator

    static Logger *m_pInstance;
  protected:
    Logger() {}
};

Logger *Logger::m_pInstance = NULL;

Logger *Logger::Instance() {
  if (!m_pInstance)
    m_pInstance = new Logger;
  return m_pInstance;
}
