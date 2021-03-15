// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: ins.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.drivers.gnss
{

    [global::ProtoBuf.ProtoContract()]
    public partial class InsStat : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public InsStat()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::apollo.common.Header header { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        public uint ins_status
        {
            get { return __pbn__ins_status.GetValueOrDefault(); }
            set { __pbn__ins_status = value; }
        }
        public bool ShouldSerializeins_status()
        {
            return __pbn__ins_status != null;
        }
        public void Resetins_status()
        {
            __pbn__ins_status = null;
        }
        private uint? __pbn__ins_status;

        [global::ProtoBuf.ProtoMember(3)]
        public uint pos_type
        {
            get { return __pbn__pos_type.GetValueOrDefault(); }
            set { __pbn__pos_type = value; }
        }
        public bool ShouldSerializepos_type()
        {
            return __pbn__pos_type != null;
        }
        public void Resetpos_type()
        {
            __pbn__pos_type = null;
        }
        private uint? __pbn__pos_type;

    }

    [global::ProtoBuf.ProtoContract()]
    public partial class Ins : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public Ins()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        public global::apollo.common.Header header { get; set; }

        [global::ProtoBuf.ProtoMember(2)]
        public double measurement_time
        {
            get { return __pbn__measurement_time.GetValueOrDefault(); }
            set { __pbn__measurement_time = value; }
        }
        public bool ShouldSerializemeasurement_time()
        {
            return __pbn__measurement_time != null;
        }
        public void Resetmeasurement_time()
        {
            __pbn__measurement_time = null;
        }
        private double? __pbn__measurement_time;

        [global::ProtoBuf.ProtoMember(3)]
        [global::System.ComponentModel.DefaultValue(Type.Invalid)]
        public Type type
        {
            get { return __pbn__type ?? Type.Invalid; }
            set { __pbn__type = value; }
        }
        public bool ShouldSerializetype()
        {
            return __pbn__type != null;
        }
        public void Resettype()
        {
            __pbn__type = null;
        }
        private Type? __pbn__type;

        [global::ProtoBuf.ProtoMember(4)]
        public global::apollo.common.PointLLH position { get; set; }

        [global::ProtoBuf.ProtoMember(5)]
        public global::apollo.common.Point3D euler_angles { get; set; }

        [global::ProtoBuf.ProtoMember(6)]
        public global::apollo.common.Point3D linear_velocity { get; set; }

        [global::ProtoBuf.ProtoMember(7)]
        public global::apollo.common.Point3D angular_velocity { get; set; }

        [global::ProtoBuf.ProtoMember(8)]
        public global::apollo.common.Point3D linear_acceleration { get; set; }

        [global::ProtoBuf.ProtoMember(9, IsPacked = true)]
        public float[] position_covariance { get; set; }

        [global::ProtoBuf.ProtoMember(10, IsPacked = true)]
        public float[] euler_angles_covariance { get; set; }

        [global::ProtoBuf.ProtoMember(11, IsPacked = true)]
        public float[] linear_velocity_covariance { get; set; }

        [global::ProtoBuf.ProtoMember(12, IsPacked = true)]
        public float[] angular_velocity_covariance { get; set; }

        [global::ProtoBuf.ProtoMember(13, IsPacked = true)]
        public float[] linear_acceleration_covariance { get; set; }

        [global::ProtoBuf.ProtoContract()]
        public enum Type
        {
            [global::ProtoBuf.ProtoEnum(Name = @"INVALID")]
            Invalid = 0,
            [global::ProtoBuf.ProtoEnum(Name = @"CONVERGING")]
            Converging = 1,
            [global::ProtoBuf.ProtoEnum(Name = @"GOOD")]
            Good = 2,
        }

    }

}

#pragma warning restore 0612, 1591, 3021
