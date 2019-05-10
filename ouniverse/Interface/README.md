# INTERFACE
Holds access to some broader / generic system. These classes are designed to function like wrappers so that they have their internals changed to other approaches / 3rd parties without breaking functionality.
* **File** is basic OS file system functionality like read, write, delete, and gather files or folders in directories.
* **Json** wraps around Json parsing functionality. The current implementation is using **rapidjson**. JSON writing is handled separately using  my our JsonWriter utility so that complex Temporary structs for marshaling are not needed.