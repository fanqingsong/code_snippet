
'''
https://stackoverflow.com/questions/42401495/how-to-dynamically-import-modules
'''

import importlib
import os

this_file_path = os.path.abspath(__file__)
this_file_dir = os.path.dirname(this_file_path)

service_path = os.path.join(this_file_dir, "service")

service_files = os.listdir(service_path)

services = {}

for one_file in service_files:
    print(one_file)

    file_name = os.path.basename(one_file)
    print(file_name)

    module_name = file_name.replace(".py", "")
    print(module_name)

    module_path = ".".join(["python", "IoCContainer", "service", module_name])
    print(module_path)

    print(os.path.splitext(file_name))

    suffix = os.path.splitext(file_name)[-1]
    if suffix == ".py":
        print("adding-----------------")
        one_module = importlib.import_module(module_path)
        one_service_class = getattr(one_module, "Service")
        services[module_name] = one_service_class()

print("=======================")
services['hello'].run()










