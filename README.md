FixedPoint
==========

Fixed Point fraction implementation.

Uses iterative method to calculate mul/div operations.



Configuration
=============

in *FixedPoint.h*

- **FIXED_OFFSET** : decimal offset. Any even number (2, 4, 6, ..., 30). (Odd number might work, but I cannot sure.)

in *FixedPoint.cpp*

- **USE_LONG_LONG** : If set to 1, mul/div use *long long* integer (64bit).
- **USE_ITERATIVE_MUL** : If set to 1, mul uses iterative method. This may provide high precision, but I cannot sure. Div always uses iterative method.



License
=======

MIT license. Read LICENSE.
