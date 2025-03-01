# MLX_FLAGS:

MLX_FLAGS = -L/usr/local/lib -lmlx -lX11 -lXext -lm -lz

##Explanation of Flags
-lmlx:

Library: MiniLibX
Purpose: This flag links against the MiniLibX library, which provides functions for creating windows, handling events, and drawing graphics. MiniLibX is commonly used in 42 Network projects for simple graphical applications.
-lX11:

Library: X11
Purpose: This flag links against the X11 library, which is the core library for the X Window System. MiniLibX relies on X11 to create and manage windows, handle input events, and perform other graphical operations on Unix-like systems.
-lXext:

Library: X11 Extension
Purpose: This flag links against the X11 extension library, which provides additional functionality and extensions to the core X11 library. MiniLibX may use some of these extensions for advanced graphical operations.
-lm:

Library: Math Library
Purpose: This flag links against the math library, which provides mathematical functions such as sin, cos, sqrt, and others. These functions are often used in graphical applications for calculations related to rendering and transformations.
-lz:

Library: zlib
Purpose: This flag links against the zlib compression library, which provides functions for data compression and decompression. MiniLibX may use zlib for handling compressed image formats or other compressed data.
