# Warnings

### Switch

Once the statement underneath a case or default label have started executing, they will overflow(fallthrough) into subsequent cases. `Break` and `return` statements are used to prevent this.