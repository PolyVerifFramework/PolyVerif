// This file was generated by a tool; you should avoid making direct changes.
// Consider using 'partial classes' to extend these types
// Input: scenario.proto

#pragma warning disable 0612, 1591, 3021
namespace apollo.prediction
{

    [global::ProtoBuf.ProtoContract()]
    public partial class Scenario : global::ProtoBuf.IExtensible
    {
        private global::ProtoBuf.IExtension __pbn__extensionData;
        global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
        {
            return global::ProtoBuf.Extensible.GetExtensionObject(ref __pbn__extensionData, createIfMissing);
        }
        public Scenario()
        {
            OnConstructor();
        }

        partial void OnConstructor();

        [global::ProtoBuf.ProtoMember(1)]
        [global::System.ComponentModel.DefaultValue(Type.Unknown)]
        public Type type
        {
            get { return __pbn__type ?? Type.Unknown; }
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

        [global::ProtoBuf.ProtoMember(2)]
        [global::System.ComponentModel.DefaultValue("")]
        public string junction_id
        {
            get { return __pbn__junction_id ?? ""; }
            set { __pbn__junction_id = value; }
        }
        public bool ShouldSerializejunction_id()
        {
            return __pbn__junction_id != null;
        }
        public void Resetjunction_id()
        {
            __pbn__junction_id = null;
        }
        private string __pbn__junction_id;

        [global::ProtoBuf.ProtoContract()]
        public enum Type
        {
            [global::ProtoBuf.ProtoEnum(Name = @"UNKNOWN")]
            Unknown = 0,
            [global::ProtoBuf.ProtoEnum(Name = @"CRUISE")]
            Cruise = 1000,
            [global::ProtoBuf.ProtoEnum(Name = @"CRUISE_URBAN")]
            CruiseUrban = 1001,
            [global::ProtoBuf.ProtoEnum(Name = @"CRUISE_HIGHWAY")]
            CruiseHighway = 1002,
            [global::ProtoBuf.ProtoEnum(Name = @"JUNCTION")]
            Junction = 2000,
            [global::ProtoBuf.ProtoEnum(Name = @"JUNCTION_TRAFFIC_LIGHT")]
            JunctionTrafficLight = 2001,
            [global::ProtoBuf.ProtoEnum(Name = @"JUNCTION_STOP_SIGN")]
            JunctionStopSign = 2002,
        }

    }

}

#pragma warning restore 0612, 1591, 3021
