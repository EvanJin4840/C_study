### const

- Means “read‑only through this name.”

* You cannot modify the object via a const variable or pointer, but the memory itself might still change (e.g., if another non‑const pointer writes to it).

* Common uses:

- Function parameters that should not be changed: void foo(const char \*s);
- Read‑only global tables or configuration data.

#### volatile

- Tells the compiler “this value can change unexpectedly; do not optimize away reads/writes.”
- Used when the value may change outside normal program flow:
  - Memory‑mapped device registers.
  - Variables updated by an interrupt handler or another thread without proper synchronization.
- Without volatile, the compiler might cache the value in a register and never see hardware/ISR updates.
