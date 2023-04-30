use rand::Rng;
use std::fs;
use std::path::Path;

fn file_creator(limit: &i32, filename: &str, type_of_sort: Option<bool>, path_string: &mut String) {
    let mut rng = rand::thread_rng();
    let mut rand_array = Vec::<u32>::new();
    let mut count = 1;
    while count < *limit {
        let random_num: u32 = rng.gen();
        rand_array.push(random_num);
        count += 1;
    }

    match type_of_sort {
        Some(true) => {
            rand_array.sort();
            fs::create_dir_all("datasets/ascending").expect(
                "The folder either already exists or has not granted the code write permissions",
            );
            *path_string = format!("datasets/ascending/{}.csv", filename);
        }
        Some(false) => {
            rand_array.sort_by(|a, b| b.cmp(a));
            fs::create_dir_all("datasets/descending").expect(
                "The folder either already exists or has not granted the code write permissions",
            );
            *path_string = format!("datasets/descending/{}.csv", filename);
        }
        None => {
            fs::create_dir_all("datasets/unsorted").expect(
                "The folder either already exists or has not granted the code write permissions",
            );
            *path_string = format!("datasets/unsorted/{}.csv", filename);
        }
    }
    let path = Path::new(&path_string);
    let final_array = format!("{:?}", &rand_array);
    fs::write(path, final_array).expect("");
}

fn main() {
    let mut limits = Vec::<i32>::new();
    let mut limit_count = 10_000;
    fs::create_dir_all("datasets")
        .expect("The folder either already exists or has not granted the code write permissions");
    while limit_count <= 100_000 {
        limits.push(limit_count);
        limit_count += 10_000;
    }

    let mut file_count = 0;
    let mut filenames = Vec::<String>::new();
    while file_count <= 10 {
        let temp_string = format!("data{}", file_count);
        filenames.push(temp_string);
        file_count += 1;
    }

    let sorted = true;
    let mut path_string = String::new();
    let sorted_descending = false;
    for i in 1..10 {
        file_creator(&limits[i], &filenames[i], Some(sorted), &mut path_string);
        file_creator(
            &limits[i],
            &filenames[i],
            Some(sorted_descending),
            &mut path_string,
        );
        file_creator(&limits[i], &filenames[i], None, &mut path_string);
    }
}
