import Foundation
import CommonCrypto

// begin code taken from https://stackoverflow.com/questions/32163848/how-can-i-convert-a-string-to-an-md5-hash-in-ios-using-swift

func MD5(_ string: String) -> String? {
    let length = Int(CC_MD5_DIGEST_LENGTH)
    var digest = [UInt8](repeating: 0, count: length)
    
    if let d = string.data(using: String.Encoding.utf8) {
        _ = d.withUnsafeBytes { (body: UnsafePointer<UInt8>) in
            CC_MD5(body, CC_LONG(d.count), &digest)
        }
    }
    
    return (0..<length).reduce("") {
        $0 + String(format: "%02x", digest[$1])
    }
}

// end code taken from stackoverflow

func part1(_ input: String) -> Int {
    var ret = 0
    while true {
        let testString: String = "\(input)\(ret)"
        if let md5String = MD5(testString) {
            let fifthIndex = md5String.index(md5String.startIndex, offsetBy: 4)
            if md5String[md5String.startIndex...fifthIndex] == "00000" {
                break
            }
        }
        ret += 1
    }
    return ret
}

print(part1("cxdnnyjw"))