import ray

# Load data.
dataset = ray.data.read_csv("s3://anonymous@air-example-data/breast_cancer.csv")

# Split data into train and validation.
train_dataset, valid_dataset = dataset.train_test_split(test_size=0.3)

# Create a test dataset by dropping the target column.
test_dataset = valid_dataset.drop_columns(cols=["target"])
