void amplitude(float n, float milliseconds) {
  if (milliseconds <= 0.0) {
    amplitude(n);
    return;
  }
  if (n > 1.0) n = 1.0;
  else if (n < -1.0) n = -1.0;
  int32_t c = (int32_t)(milliseconds*(AUDIO_SAMPLE_RATE_EXACT/1000.0));
  if (c == 0) {
    amplitude(n);
    return;
  }
  int32_t t = (int32_t)(n * 2147418112.0);
  __disable_irq();
  target = t;
  if (target == magnitude) {
    state = 0;
    __enable_irq();
    return;
  }
  increment = substract_int32_then_divide_int32(target, magnitude, c);
  if (increment == 0) {
    increment = (target > magnitude) ? 1 : -1;
  }
  state = 1;
  __enable_irq();
}
float read(void) {
  int32_t m = magnitude;
  return (float)m * (1.0 / 2147418112.0);
}
