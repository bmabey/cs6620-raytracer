
#ifndef Timer_h
#define Timer_h

class Timer {
 public:
  static double currentSeconds();
 private:
  Timer();
  Timer(const Timer&);
  Timer& operator=(const Timer&);

  static void initialize();
};

#endif
