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
