from hub import Dataset, schema
import numpy as np

ds = Dataset(
    "./data/dataset_name",  # file path to the dataset
    shape = (4,),  # follows numpy shape convention
    mode = "w+",  # reading & writing mode
    schema = {  # named blobs of data that may specify types
    # Tensor is a generic structure that can contain any type of data
        "image": schema.Tensor((512, 512), dtype="float"),
        "label": schema.Tensor((512, 512), dtype="float"),
    }
)

# filling the data containers with data (here - zeroes to initialize)
ds["image"][:] = np.zeros((4, 512, 512))
ds["label"][:] = np.zeros((4, 512, 512))
ds.flush()  # executing the creation of the dataset